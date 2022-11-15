#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll P = 27;
const int MAX = 1e5 + 10;
ll pw[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	pw[0] = 1;
	for(int i = 1; i < MAX; i ++) pw[i] = P * pw[i - 1];
	int t; cin >> t;
	while(t --) {
		string s; cin >> s;
		int n = s.size();
		string rs = s;
		reverse(rs.begin(), rs.end());
		ll h[n][n], rh[n][n];
		for(int i = 0; i < n; i ++) {
			ll cur = 0;
			for(int j = i; j < n; j ++) {
				cur += 1LL * (s[j] - 'a' + 1) * pw[j - i];
				h[i][j] = cur;
			}
		}
		for(int i = 0; i < n; i ++) {
			ll cur = 0;
			for(int j = i; j < n; j ++) {
				cur += 1LL * (rs[j] - 'a' + 1) * pw[j - i];
				rh[n - j - 1][n - i - 1] = cur;
			}
		}
		set <ll> cnt;
		for(int i = 0; i < n; i ++) {
			ll pref = (i ? h[0][i - 1] : 0);
			for(int j = i; j < n; j ++) {
				ll rev = pw[i] * rh[i][j];
				ll suff = (j == n - 1 ? 0 : h[j + 1][n - 1]) * pw[j + 1];
				ll cur = pref + rev + suff;
				cnt.insert(cur);
			}
		}
		cout << cnt.size() << "\n";
	}	
	
	return 0;
}
