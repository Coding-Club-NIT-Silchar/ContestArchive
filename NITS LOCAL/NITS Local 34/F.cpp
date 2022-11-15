#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 5005;
vector <int> g[MAX];
ll ans = 0;
int bridge, n, m;
int d[MAX], low[MAX][MAX];
int s[MAX], t[MAX];
bool vis[MAX];
void dfs1(int u, int src) {
    for(int v : g[u]) {
        if(vis[v] || d[v] != d[u] + 1) continue;
        vis[v] = true;
        if(t[v] < d[src] && s[v] == s[src]) ans ++;
        dfs1(v, src);
    }
}
void dfs0(int u, int p, int dep) {
    d[u] = dep;
    s[u] = (p > 0);
    t[u] = 1;
    for(int v : g[u]) {
        if(v == p) continue;
        if(d[v] == 0) {
            dfs0(v, u, dep + 1);
            for(int i = 1; i <= dep; i ++) low[u][i] += low[v][i];
        }
        else if(d[v] < d[u]) low[u][d[v]] ++;
    }
    for(int i = 1; i < dep; i ++) {
        if(low[u][i] > 0) {
            t[u] = i;
            s[u] += low[u][i];
        }
    }
    if(s[u] == 1) bridge ++;
    else if(s[u] == 2) ans ++;
    if(s[u] != 1) {
        memset(vis, false, sizeof(vis));
        dfs1(u, u);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs0(1, 0, 1);
    ans += 1LL * bridge * (bridge - 1) / 2;
    ans += 1LL * bridge * (m - bridge);
    cout << ans;

    return 0;
}
