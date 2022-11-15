/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
const int LOGN = ceil(log2(N)) + 1;
bool vis[N], bridge[N];
vector <int> G[N], T[N];
int cmp[N], tin[N], low[N], level[N], par[LOGN][N], tim, cmpno;
ll dis[N], a[N];
map <pair <int, int>, int> edge;
pair <int, int> edges[N];
void dfs0(int u, int p, ll val) {
	par[0][u] = p, dis[u] = val;
	for(int v : T[u]) {
		if(v != p) {
			level[v] = level[u] + 1;
			dfs0(v, u, val + a[v]);
		}
	}
}
void precompute() {
	for(int i = 1; i < LOGN; i ++) {
		for(int j = 1; j <= N; j ++) {
			if(par[i - 1][j]) par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
}
int LCA(int u, int v) {
	if(level[u] < level[v]) swap(u, v);
	int diff = level[u] - level[v];
	for(int i = LOGN - 1; i >= 0; i --) {
		if((1 << i) & diff) u = par[i][u];
	}
	if(u == v) return u;
	for(int i = LOGN - 1; i >= 0; i --) {
		if(par[i][u] && par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
	}
	return par[0][u];
}
void dfs(int u, int p = 0) {
	vis[u] = true;
	tin[u] = low[u] = tim ++;
	for(int v : G[u]) {
		if(v == p) continue;
		if(vis[v]) low[u] = min(low[u], tin[v]);
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > tin[u]) bridge[edge[{u, v}]] = true;
		}
	}
}
void dfs1(int u) {
	vis[u] = true, a[cmpno] ++, cmp[u] = cmpno;
	for(int v : G[u]) {
		if(!vis[v]) dfs1(v);
	}
}
ll query(int u, int v) {
	int lca = LCA(u, v);
	return dis[u] + dis[v] - 2 * dis[lca] + a[lca];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		edge[{u, v}] = edge[{v, u}] = i;
		edges[i] = {u, v};
	}
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));
	dfs(1);
	for(int i = 1; i <= n; i ++) G[i].clear();
	for(int i = 1; i <= m; i ++) {
		if(bridge[i]) continue;
		int u = edges[i].first, v = edges[i].second;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; i ++) {
		if(vis[i]) continue;
		cmpno ++;
		dfs1(i);
	}
	for(int i = 1; i <= m; i ++) {
		if(!bridge[i]) continue;
		int u = edges[i].first, v = edges[i].second;
		u = cmp[u], v = cmp[v];
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs0(1, 0, a[1]);
	precompute();
	int q; cin >> q;
	while(q --) {
		int u, v;
		cin >> u >> v;
		u = cmp[u], v = cmp[v];
		cout << query(u, v) << "\n";
	}
	
	return 0;
}
