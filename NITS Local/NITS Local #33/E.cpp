#include<bits/stdc++.h>
using namespace std; 

const int N = 1e5 ;
vector<int> g[N], h, vis;
bool cycle ; 

void dfs(int u) {
    if(cycle) return ; 
    vis[u] = 1 ; 
    h[u] = 1 ; 

    for(auto v : g[u]) {
        if(vis[v] == 1) 
            cycle = true ; 
        
        if(vis[v] == 0) 
            dfs(v) ;

        h[u] = max(h[u], 1 + h[v]) ; 
    }

    vis[u] = 2 ; 
}

int main() {

    ios::sync_with_stdio(0) ; 
    cin.tie(0) ; 

    int tests; 
    cin >> tests ; 

    while(tests--) {

        int n, m ; 
        cin >> n >> m ; 

        for(int i = 0 ; i < n ; ++i) 
            g[i].clear() ; 

        h.clear() ; 
        vis.clear() ; 

        h.resize(n) ; 
        vis.resize(n) ; 
        
        vector<int> u(m), v(m) ; 

        for(int i = 0 ; i < m ; ++i) {
            cin >> u[i] >> v[i] ; 
            g[u[i]-1].push_back(v[i]-1) ; 
        }
        
        cycle = false ; 
        for(int i = 0 ; i < n ; ++i) 
            if(vis[i] == 0) 
                dfs(i) ; 

        if(cycle) {
            cout << "NO\n" ; 
            continue ; 
        }

        cout << "YES\n" ; 

        for(int i = 0 ; i < n ; ++i) {
            cout << h[i] << " " ; 
        }

        cout << '\n'; 
    }

    return 0 ; 
}
