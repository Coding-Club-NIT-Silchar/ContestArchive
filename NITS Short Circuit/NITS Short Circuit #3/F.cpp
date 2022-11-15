#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool cycle[N], vis[N], cycle_found ;
int p[N], par[N][20], d[N];
vector<int> g[N] ;

void dfs(int u, int parent = 0) {
    vis[u] = 1 ;
    for(auto v : g[u]) {
        if(!vis[v]) {
            p[v] = u;
            dfs(v, u) ;
        }
        else if(v != parent && !cycle_found) { // mark all the nodes on the cycle
            int t = u;
            while(t != v) {
                cycle[t] = 1;
                t = p[t] ;
            }
            cycle[t] = 1;
            cycle_found = 1 ;
        }
    }
}

void dfs2(int u, int parent = 0) {
    par[u][0] = parent ;
    for(int i = 1 ; i < 20 ; ++i) {
        par[u][i] = par[par[u][i-1]][i-1] ;
    }
    for(auto v : g[u]) {
        if(!cycle[v] && v != parent) {
            d[v] = d[u] + 1;
            dfs2(v, u);
        }
    }
}

int LCA(int u, int v) {
    if(d[u] < d[v]) swap(u, v) ;
    for(int i = 19 ; i >= 0 ; --i) {
        if(par[u][i] > 0 && d[par[u][i]] >= d[v]) u = par[u][i] ;
    }
    if(u == v) return u ;
    int lg = 19 ;
    while(par[u][0] != par[v][0]) {
        if(par[u][lg] != par[v][lg]) {
            u = par[u][lg] ;
            v = par[v][lg] ;
        }
        lg -- ;
    }
    return par[u][0] ;
} 

int main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q ;
        // Reset the global variables
        for(int i = 1 ; i <= n ; ++i) {
            g[i].clear() ;
            cycle[i] = vis[i] = d[i] = p[i] = 0 ;
            for(int j = 0 ; j < 20 ; ++j) {
                par[i][j] = 0 ;
            }
        }
        cycle_found = 0;
        for(int i = 0 ; i < n ; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }
        dfs(1) ;
        int cycle_edges = 0 ;
        // dfs again with cycle nodes being the root node
        for(int i = 1 ; i <= n ; ++i) {
            if(cycle[i]) {
                dfs2(i) ;
                ++cycle_edges ;
            }
        }
    
        while(q--) {
            int u, v, k; cin >> u >> v >> k ;
            int lca = LCA(u, v);
            if(lca == 0) { // u and v are part of different trees
                // First color all the edges not part of any path.
                int rem_edges = max(0, k - (n - d[u] - d[v] - cycle_edges)) ;
                if(rem_edges <= cycle_edges) { // Then color edges part of the cycle.
                    cout << rem_edges << '\n' ;
                }
                else { // Then color any of the uncolored edges.
                    cout << cycle_edges + 2 * (rem_edges - cycle_edges) << '\n';
                }
            }
            else {
                int edges = d[u] + d[v] - 2 * d[lca] ;
                if(!cycle[lca]) { // LCA is not part of the cycle
                    cout << max(0, k - n + edges) << '\n' ;
                }
                else {
                    int rem_edges = max(0, k - n + (cycle_edges + d[u] + d[v] - 2 * d[lca])) ;
                    if(rem_edges <= cycle_edges) { // Then color edges part of the cycle.
                        cout << rem_edges << '\n' ;
                    }
                    else { // Then color any of the uncolored edges.
                        cout << cycle_edges + 2 * (rem_edges - cycle_edges) << '\n';
                    }
                }
            }
        }
    }

    return 0;
}
