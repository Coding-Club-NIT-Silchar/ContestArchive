#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;
vector<int> g[N];
int dp[N], ans;

void dfs(int node, int p = 0) {
    dp[node] = 1;
    for(auto i : g[node]) {
        if(i != p) {
            dfs(i, node);
            if(node > i) dp[node] += dp[i];
        }
    }
}

void reroot(int node, int p = 0) {
    vector<int> pf;
    for(auto i : g[node]) {
        if(i < node) pf.push_back(dp[i]);
        else pf.push_back(0);
    }
    for(int i = 1; i < (int)pf.size(); ++i) pf[i] += pf[i - 1];
    int c = 0;
    for(auto i : g[node]) {
        ans += (c ? pf[c - 1] : 0) * (pf[c] - (c ? pf[c - 1] : 0));
        int xdpn = dp[node];
        int xdpi = dp[i];
        if(i > node) {
            dp[i] += dp[node];
        }
        else {
            dp[node] -= dp[i];
        }
        if(i != p) reroot(i, node);
        dp[node] = xdpn;
        dp[i] = xdpi;
        ++ c;
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) g[i].clear(), dp[i] = 0;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    ans = 0;
    reroot(1);
    cout << ans << '\n';
}

signed main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T --) {
        solve();
    }

    return 0;
}
