#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 405;
template <int SZ> struct  Dinic {
    int N = 0, s, t;
    typedef ll F; // define type of flow
    struct Edge {int to, rev; F flow, cap; int id;};
    vector <Edge> adj[SZ];
    void addEdge(int u, int v, F cap, int id = 0) {
        N = max(N, max(u, v) + 1);
        Edge a = {v, (int) adj[v].size(), 0, cap, id}, b = {u, (int) adj[u].size(), 0, 0, 0};
        adj[u].push_back(a), adj[v].push_back(b);
    }
    int lvl[SZ]; typename vector <Edge>::iterator cur[SZ];
    bool bfs() {
        for(int i = 0; i < SZ; i ++) lvl[i] = -1, cur[i] = adj[i].begin();
        queue <int> q({s}); lvl[s] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &e : adj[u]) if(lvl[e.to] == -1 && e.flow < e.cap) {
                q.push(e.to);
                lvl[e.to] = lvl[u] + 1;
            }
        }
        return lvl[t] >= 0;
    }
    F dfs(int u, F flow) {
        if(u == t || !flow) return flow;
        for(; cur[u] != adj[u].end(); cur[u] ++) {
            Edge &e = *cur[u];
            if(lvl[e.to] != lvl[u] + 1 || e.flow == e.cap) continue;
            F df = dfs(e.to, min(flow, e.cap - e.flow));
            if(df) {
                e.flow += df; adj[e.to][e.rev].flow -= df;
                return df;
            }
        }
        return 0;
    }
    F maxFlow(int _s, int _t) {
        s = _s, t = _t;
        F totFlow = 0;
        while(bfs()) {
            F df = dfs(s, numeric_limits <F>::max());
            while(df) {
                totFlow += df;
                df = dfs(s, numeric_limits <F>::max());
            }
        }
        return totFlow;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m, p;
    cin >> n >> m >> p;
    Dinic <MAX> Network;
    int s = 0, t = n + m + 2 * p + 1;
    for(int i = 1; i <= n; i ++) Network.addEdge(s, i, 1);
    for(int i = 1; i <= m; i ++) Network.addEdge(n + 2 * p + i, t, 1);
    for(int i = 1; i <= p; i ++) {
        int a, b;
        cin >> a >> b;
        int u = n + 2 * i - 1, v = n + 2 * i;
        Network.addEdge(u, v, 1);
        for(int i = 1; i <= a; i ++) {
            int x; cin >> x;
            Network.addEdge(x, u, 1);
        }
        for(int i = 1; i <= b; i ++) {
            int x; cin >> x;
            Network.addEdge(v, n + 2 * p + x, 1);
        }
    }
    int flow = Network.maxFlow(s, t);
    cout << flow;

    return 0;
}
