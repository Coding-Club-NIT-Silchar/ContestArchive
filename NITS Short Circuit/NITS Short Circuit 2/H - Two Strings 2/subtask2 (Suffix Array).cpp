#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 8e5 + 10;
const ll MOD = 1e9 + 7;
int poss[MAX];
ll dp[MAX], pre[MAX];
void add(ll &a, ll b) {
	b %= MOD;
	a = (a + b) % MOD;
}
void sub(ll &a, ll b) {
	b %= MOD;
	a = (a - b) % MOD;
	a = (a + MOD) % MOD;
}
template <class T> struct SegTree {
	const T ID = MAX;
	int n; vector <T> seg;
	T comb(T a, T b) { return min(a, b); }
	SegTree(int _n) { n = _n; seg.assign(2 * n, ID); }
	void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }
	void update(int idx, T val) {
		seg[idx += n] = val;
		for(idx /= 2; idx; idx /= 2) pull(idx);
	}
	T query(int l, int r) {
		T lnode = ID, rnode = ID;
		for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if(l & 1) lnode = comb(lnode, seg[l ++]);
			if(r & 1) rnode = comb(seg[-- r], rnode);
		}
		return comb(lnode, rnode);
	}
};
void countSort(vector <int> &p, vector <int> &c) {
	int n = p.size();
	vector <int> cnt(n), pos(n);
	for(int x : c) cnt[x] ++;
	pos[0] = 0;
	for(int i = 1; i < n; i ++) pos[i] = pos[i - 1] + cnt[i - 1];
	vector <int> p_new(n);
	for(int x : p) {
		int idx = c[x];
		p_new[pos[idx] ++] = x;
	}
	p = p_new;
}
struct SuffixArray {
	string s; int n;
	vector <int> p, c, lcp;
	SuffixArray(string &cur) {
		s = cur + "$"; n = s.size();
		p.resize(n), c.resize(n), lcp.resize(n);
		buildSA(); buildLCP();
	}
	void buildSA() {
		vector <pair <int, int>> v(n);
		for(int i = 0; i < n; i ++) v[i] = {s[i], i};
		sort(v.begin(), v.end());
		for(int i = 0; i < n; i ++) p[i] = v[i].second;
		c[p[0]] = 0;
		for(int i = 1; i < n; i ++) {
			c[p[i]] = v[i].first == v[i - 1].first ? c[p[i - 1]] : c[p[i - 1]] + 1;
		}
		int k = 0;
		while((1 << k) < n) {
			for(int i = 0; i < n; i ++) p[i] = (p[i] - (1 << k) + n) % n;
			countSort(p, c);
			vector <int> c_new(n);
			c_new[p[0]] = 0;
			for(int i = 1; i < n; i ++) {
				pair <int, int> a = {c[p[i]], c[(p[i] + (1 << k)) % n]}, b = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
				c_new[p[i]] = a == b ? c_new[p[i - 1]] : c_new[p[i - 1]] + 1;
			}
			c = c_new;
			k ++;
		}
	}
	void buildLCP() {
		int k = 0;
		for(int i = 0; i < n - 1; i ++) {
			int pi = c[i]; int j = p[pi - 1];
			while(s[i + k] == s[j + k]) k ++;
			lcp[pi] = k;
			k = max(k - 1, 0);
		}
	}
};
ll get(int l, int r) {
	ll ret = pre[r];
	if(l) sub(ret, pre[l - 1]);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s, t;
	cin >> s >> t;
	string tmp = s, cur;
	reverse(tmp.begin(), tmp.end());
	cur = tmp + "@";
	tmp = t;
	reverse(tmp.begin(), tmp.end());
	cur += tmp;
	SuffixArray SA(cur);
	int mid = s.size();
	SegTree <int> seg(MAX);
	for(int i = 0; i < SA.n; i ++) seg.update(i, SA.lcp[i]);
	set <int> post;
	for(int i = 0; i < SA.n; i ++) {
		if(SA.p[i] < mid) poss[(int) s.size() - SA.p[i]] = i;
		else post.insert(i);
	}
	s = "X" + s;
	dp[0] = 1, pre[0] = 1;
	for(int i = 1; i < (int) s.size(); i ++) {
		int curposs = poss[i];
		int len = 0;
		auto it = post.upper_bound(curposs);
		if(it != post.end()) len = max(len, seg.query(curposs + 1, *it));
		if(it != post.begin()) len = max(len, seg.query(*prev(it) + 1, curposs));
		if(!len) return cout << 0, 0;
		add(dp[i], get(i - len, i - 1));
		add(pre[i], pre[i - 1] + dp[i]);
	}
	cout << dp[(int) s.size() - 1];

	return 0;
}
