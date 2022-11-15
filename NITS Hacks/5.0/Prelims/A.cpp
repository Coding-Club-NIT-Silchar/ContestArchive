#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 1;
vector<int> g[N];
int ans[N];
set<pair<int, int>> st[N];

void dfs(int node, int p = 0) {
    st[node].insert({0, node});
    for(auto i : g[node]) {
        if(i == p) continue;
        dfs(i, node);
        st[node].insert({st[i].rbegin() -> first + 1, st[i].rbegin() -> second});
        if(st[node].size() > 2) st[node].erase(st[node].begin());
    }
}

void rem(set<pair<int, int>> &a, set<pair<int, int>> &b) {
    for(auto i : b) {
        auto it = a.find({i.first + 1, i.second});
        if(it != a.end()) a.erase(it);
    }
}

void reroot(int node, int p = -1) {
    ans[node] = st[node].rbegin() -> first;;
    for(auto i : g[node]) {
        if(i == p) continue;
        auto ex = st[node];
        auto ex2 = st[i];
        rem(st[node], st[i]);
        st[i].insert({st[node].rbegin() -> first + 1, st[node].rbegin() -> second});
        if((int)st[i].size() > 2) {
            st[i].erase(st[i].begin());
        }
        reroot(i, node);
        st[node] = ex;
        st[i] = ex2;
    }
}

struct DSU{  
        int n;
        vector<int> par, rnk ;
        
        DSU(int _n) {
            n = _n + 5 ; 
            par.resize(n) ; 
            rnk.resize(n) ;
            for(int i = 1 ; i < n ; ++i) par[i] = i ; 
        }
         
        int find_set(int a) {
            return (a == par[a] ? a : par[a] = find_set(par[a])) ; 
        }
         
        void union_set(int a, int b) {
            a = find_set(a) ; 
            b = find_set(b) ; 
            if(a != b) {
                if(rnk[a] < rnk[b]) swap(a, b) ; 
                par[b] = a ; 
                if(rnk[a] == rnk[b]) ++rnk[a] ; 
            }
        }
};

int sum = 0;

void solve() {
    int n, k;
    cin >> n >> k;
    sum += n;
    assert(1 <= sum && sum <= 2e5);
    assert(1 <= k && k <= n && n <= 2e5);
    for(int i = 1; i <= n; ++i) g[i].clear(), st[i].clear();
    DSU d(n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        assert(u != v);
        assert(d.find_set(u) != d.find_set(v));
        d.union_set(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    reroot(1);
    for(int i = 1; i <= n; ++i) {
        ans[i] = 2 * (k - 1) - min(ans[i], k - 1);
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }

    return 0;
}
