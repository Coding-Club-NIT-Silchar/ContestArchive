#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
vector<int> g[N];
bool vis[N];
int d[N];
vector<int> st;

void dfs(int node, int h) {
    d[node] = h;
    vis[node] = 1;
    st.push_back(node);
    for(auto i : g[node]) {
        if(!vis[i]) {
            dfs(i, h + 1);
        }
    }
}

int dfs(int node) {
    vis[node] = 1;
    int ans = 0;
    for(auto i : g[node]) {
        if(!vis[i]) {
            ans = max(ans, 1 + dfs(i));
        }
    }
    return ans;
}


signed main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            ++ cnt;
            st.clear();
            dfs(i, 0);
            int root = i, mx = 0;
            for(auto j : st) {
                vis[j] = 0;
                if(d[j] > mx) {
                    mx = d[j];
                    root = j;
                }
            }
            ans += dfs(root);
        }
    }

    cout << ans + cnt - 1;

    return 0;
}
