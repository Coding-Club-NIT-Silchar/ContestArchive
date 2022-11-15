#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 10;
vector <int> og[MAX], g[MAX], sw[MAX];
int par[MAX], x[MAX], ans[MAX];
bool vis[MAX];
map <pair <int, int>, int> edge, en;
void dfs(int u, int p) {
	par[u] = p;
	for(int v : og[u]) {
		if(v == p) continue;
		dfs(v, u);
	}
}
void dfs1(int u, int state) {
	ans[u] = state;
	vis[u] = true;
	for(int v : g[u]) {
		if(vis[v]) continue;
		if(en[{u, v}]) dfs1(v, state ^ 1);
		else dfs1(v, state);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, s, t;
	cin >> n >> s >> t;
	// input the given tree
	for(int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v >> x[i];
		og[u].push_back(v);
		og[v].push_back(u);
		edge[{u, v}] = edge[{v, u}] = i;
	}

	// input the switches. sw[i] represents the two switches controlling edge 'i'
	int m; cin >> m;
	for(int i = 0; i < m; i ++) {
		int k; cin >> k;
		while(k --) {
			int e; cin >> e;
			sw[e - 1].push_back(i);
		}
	}

	dfs(s, 0);

	// get the edges on the path from s -> t
	set <int> on_path;
	int cur = t;
	while(cur) {
		if(par[cur]) on_path.insert(edge[{par[cur], cur}]);
		vis[cur] = true;
		cur = par[cur];
	} 

	// get the edges such that exactly one of their endpoints lie on the path from s -> t
	set <int> off_path;
	cur = t;
	while(cur) {
		for(int v : og[cur]) {
			if(vis[v]) continue;
			off_path.insert(edge[{cur, v}]);
		}
		cur = par[cur];
	}

	// now we create the graph for m switches, where each switch is represented by a node
	// we join two nodes if both the switches control same edge
	// to each edge, we assign a number, which can have two possible values
	// 0 if we need to retain the state of this edge
	// 1 if we need to change the state of this edge

	// if the edge lies on the path from s -> t, we need to ensure that it is unlocked
	
	set <pair <int, int>> used;
	for(int e : on_path) {
		int u = sw[e][0], v = sw[e][1];
		if(used.find({u, v}) != used.end()) continue;
		used.insert({u, v}); used.insert({v, u});
		// if it is already unlocked, we need to retain it's state
		// if it is locked, we need to change it's state
		en[{u, v}] = x[e], en[{v, u}] = x[e];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	// if the edge has exactly one endpoint on the path from s -> t, we need to ensure that it is locked

	for(int e : off_path) {
		int u = sw[e][0], v = sw[e][1];
		if(used.find({u, v}) != used.end()) continue;
		used.insert({u, v}); used.insert({v, u});
		// if it is already locked, we need to retain it's state
		// if it is unlocked, we need to change it's state
		en[{u, v}] = x[e] ^ 1, en[{v, u}] = x[e] ^ 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	// since it is guaranteed that answer always exist, let's pick a random switch and fix it's final state
	// we can then find final state of other switch

	memset(vis, false, sizeof(vis));
	for(int i = 0; i < m; i ++) {
		if(vis[i]) continue;
		dfs1(i, 0);
	}

	for(int i = 0; i < m; i ++) cout << ans[i] << " ";


	
	return 0;
}
