#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
int n, d[MAX];
ll ans[MAX];
vector <int> g[MAX];
void dfs(int u, int p) {
	d[u] = 1;
	for(int v : g[u]) {
		if(v == p) continue;
		dfs(v, u);
		d[u] = max(d[u], d[v] + 1);
	}
}
void solve(int u, int p) {
	vector <int> cur; multiset <int> ms;
	for(int v : g[u]) {
		cur.push_back(d[v]);
		ms.insert(d[v]);
	}
	while((int) cur.size() < 4) cur.push_back(0), ms.insert(0);
	sort(cur.begin(), cur.end(), greater <int>());
	vector <int> perm = {cur[3], cur[2], cur[1], cur[0]};
	do {
		int l1 = perm[0] + perm[1]; int l2 = perm[2] + perm[3];
		ans[u] = max(ans[u], 1LL * l1 * l2);
	} while(next_permutation(perm.begin(), perm.end()));
	for(int v : g[u]) {
		if(v == p) continue;
		ms.erase(ms.find(d[v]));
		int curD = d[u], newD = *ms.rbegin() + 1;
		d[u] = newD;
		solve(v, u);
		d[u] = curD;
		ms.insert(d[v]);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			g[i].clear();
			d[i] = 0, ans[i] = 0;
		}
		for(int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		solve(1, 0);
		for(int i = 1; i <= n; i ++) cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}
