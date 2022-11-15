#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e6 + 10;
vector <int> order, og[MAX], g[MAX], rg[MAX], key[MAX];
int par[MAX], x[MAX], gp[MAX], comp[MAX];
bool used[MAX];
inline int NOT(int x) { return (x ^ 1); }
inline int POS(int x) { return (2 * x); }
inline int NEG(int x) { return (2 * x + 1); } 
void add(int u, int v) {
	g[NOT(u)].push_back(v);
	g[NOT(v)].push_back(u);
	rg[v].push_back(NOT(u));
	rg[u].push_back(NOT(v));
}
void dfs1(int u, int p) {
	par[u] = p;
	for(int v : og[u]) {
		if(v == p) continue;
		dfs1(v, u);
	}
}
void dfs2(int u) {
	used[u] = true;
	for(int v : g[u]) {
		if(used[v]) continue;
		dfs2(v);
	}
	order.push_back(u);
}
void dfs3(int u, int cn) {
	comp[u] = cn;
	for(int v : rg[u]) {
		if(comp[v] != -1) continue;
		dfs3(v, cn);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q = 1;
	while(q --) {
		map <pair <int, int>, int> edge;
		vector <pair <int, int>> edges;
		int n, s, t;
		cin >> n >> s >> t;
		for(int i = 0; i <= n; i ++) og[i].clear();
		for(int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v >> x[i];
			edge[{u, v}] = edge[{v, u}] = i;
			edges.push_back({u, v});
			og[u].push_back(v);
			og[v].push_back(u);
		}
		int m; cin >> m;
		for(int i = 0; i < 2 * m; i ++) comp[i] = -1;
		for(int i = 0; i < m; i ++) {
			int k; cin >> k;
			while(k --) {
				int e; cin >> e;
				key[e - 1].push_back(i);
			}
		}
		dfs1(s, 0);
		int cur = t;
		vector <int> path, st[2];
		vector <bool> a(n, false);
		while(cur) {
			path.push_back(cur);
			a[cur] = true;
			cur = par[cur];
			if(cur) {
				int e = edge[{cur, path.back()}];
				st[1].push_back(e);
			}
		}
		reverse(path.begin(), path.end());
		for(int i = 0; i < n - 1; i ++) {
			auto e = edges[i];
			if(a[e.first] ^ a[e.second]) st[0].push_back(i);
		}
		for(int i = 0; i < 2; i ++) {
			for(int e : st[i]) {
				int p = key[e][0], q = key[e][1];
				if(x[e] ^ i) {
					add(NEG(p), POS(q));
					add(POS(p), NEG(q));
				}
				else {
					add(POS(p), POS(q));
					add(NEG(p), NEG(q));
				}
			}
		}
		order.clear();
		for(int i = 0; i < 2 * m; i ++) {
			if(!used[i]) dfs2(i);
		}
		for(int i = 0, j = 0; i < 2 * m; i ++) {
			int u = order[2 * m - 1 - i];
			if(comp[u] == -1) dfs3(u, j ++);
		}
		bool flag = true;
		for(int i = 0; i < 2 * m; i += 2) {
			if(comp[i] == comp[i + 1]) flag = false;
			gp[i / 2] = (comp[i] > comp[i + 1]);
		}
		if(!flag) {
			cout << -1 << "\n";
			continue;
		}
		for(int i = 0; i < m; i ++) cout << gp[i] << " ";
		cout << "\n";
	}	
	
	return 0;
}
