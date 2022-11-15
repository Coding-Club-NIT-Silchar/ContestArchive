#include<bits/stdc++.h>
using namespace std;
 
struct SCC{
    int n;
    vector<vector<int>> g, gr; 
    vector<int> order, comp ; 
    vector<bool> vis; 
    SCC(int _n) {
        n = _n; 
        g.resize(n+1) ; gr.resize(n+1) ; 
        comp.assign(n + 1, -1); vis.resize(n+1) ; 
    }
    void addEdge(int u, int v) {
        g[u].push_back(v) ; 
        gr[v].push_back(u) ; 
    }
    void dfs1(int node) {
        vis[node] = 1 ;
        for(auto i : g[node]) if(!vis[i]) dfs1(i) ; 
        order.push_back(node) ;  
    }
    void dfs2(int node, int c) {
        comp[node] = c ;
        for(auto i : gr[node]) if(comp[i] == -1) dfs2(i, c) ; 
    }
    vector<int> scc() {
        for(int i = 1 ; i <= n ; ++i) if(!vis[i]) dfs1(i) ; 
        int cnt = 1 ; 
        for(int i = 0 ; i < n ; ++i) {
            int v = order[n-i-1] ; 
            if(comp[v] == -1) dfs2(v, cnt++) ; 
        }
        return comp;    
    }
};
 
int main() {
 
    ios :: sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while(t --) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        SCC s(n);
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            s.addEdge(u, v);
        }
        auto comp = s.scc();
        vector<long long> sum(n + 1), cnt(n + 1), mn(n + 1, 1e9);
        for(int i = 1; i <= n; ++i) {
            sum[comp[i]] += a[i];
            cnt[comp[i]] ++;
            mn[comp[i]] = min(mn[comp[i]], i * 1ll);
        }
        long long mx = -1, idx = -1;
        for(int i = 1; i <= n; ++i) {
            if(cnt[i] > 1) {
                if(sum[i] > mx) {
                    mx = sum[i];
                    idx = mn[i];
                }
                else if(sum[i] == mx) {
                    idx = min(idx, mn[i]);
                }
            }
        }
        cout << mx << " ";
        if(idx != -1) cout << idx;
        cout << '\n';
    }
 
    return 0;
}
