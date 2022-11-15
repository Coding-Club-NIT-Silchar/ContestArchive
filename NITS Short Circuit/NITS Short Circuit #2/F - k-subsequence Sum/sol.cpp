/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e6 + 10;
int a[MAX];
vector <vector <int>> query;
struct FenwickTree {
	ll BIT[2 * MAX] = {0};
	void update(int x, ll val) {
		for(; x < MAX; x += x & (-x)) BIT[x] += val;
	}
	ll get(int x) {
		ll sum = 0;
		for(; x > 0; x -= x & (-x)) sum += BIT[x];
		return sum;
	}
	int SearchPrefix(ll val) {
		ll sum = 0;
		int x = 0;
		for(int i = 22; i >= 0; i --) {
			if(x + (1 << i) < MAX && sum + BIT[x + (1 << i)] <= val) {
				sum += BIT[x + (1 << i)];
				x += (1 << i);
			}
		}
		return x + 1;
	}
} BIT1, BIT2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	vector <int> v;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		v.push_back(a[i]);
	}	
	for(int i = 0; i < q; i ++) {
		vector <int> cur; int t;
		cin >> t; cur.push_back(t);
		if(t == 1) {
			int x, y; 
			cin >> x >> y;
			cur.push_back(x); cur.push_back(y);
			v.push_back(y);
		}
		else {
			int k; cin >> k;
			cur.push_back(k);
		}
		query.push_back(cur);
	}
	map <int, int> cmp, org;
	for(int x : v) cmp[x] = 0;
	int c = 0;
	for(auto &p : cmp) {
		p.second = ++ c;
		org[c] = p.first;
	}
	for(int i = 1; i <= n; i ++) a[i] = cmp[a[i]];
	for(auto &cur : query) if(cur[0] == 1) cur[2] = cmp[cur[2]];
	for(int i = 1; i <= n; i ++) BIT1.update(a[i], 1), BIT2.update(a[i], org[a[i]]);
	for(int i = 0; i < q; i ++) {
		int t = query[i][0];
		if(t == 1) {
			int idx = query[i][1], nval = query[i][2];
			int curval = a[idx];
			BIT1.update(curval, -1)	, BIT2.update(curval, -org[curval]);
			BIT1.update(nval, 1), BIT2.update(nval, org[nval]);
			a[idx] = nval;
		}
		else {
			int k = query[i][1];
			int idx = BIT1.SearchPrefix(k);
			int tc = BIT1.get(idx);
			ll sum = BIT2.get(idx);
			ll sub = 1LL * (tc - k) * org[idx];
			cout << sum - sub << "\n";
		}
	}
	
	return 0;
}
