#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
int par[MAX], sz[MAX];
void init(int v) {
    par[v] = v;
    sz[v] = 1;
}
int find(int v) {
    return v == par[v] ? v : par[v] = find(par[v]);
}
void join(int u, int v) {
    u = find(u), v = find(v);
    if(u != v) {
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    map <string, int> mp;
    for(int i = 1; i <= n; i ++) {
        init(i);
        string s; cin >> s;
        mp[s] = i;
    }
    int m; cin >> m;
    vector <pair <int, int>> edges;
    for(int i = 0; i < m; i ++) {
        string u, v;
        cin >> u >> v;
        edges.push_back({mp[u], mp[v]});
    }
    int k; cin >> k;
    for(int i = 0; i < k; i ++) {
        string a, b;
        cin >> a >> b;
        int u = mp[a], v = mp[b];
        join(u, v);
    }
    int a1 = 0, a2 = 0;
    for(int i = 1; i <= n; i ++) a1 += (find(i) == i);
    set <pair <int, int>> s;
    for(int i = 0; i < m; i ++) {
        int u = edges[i].first, v = edges[i].second;
        u = find(u), v = find(v);
        if(u != v && s.find({u, v}) == s.end()) {
            a2 ++;
            s.insert({u, v});
        } 
    }
    cout << a1 << " " << a2 << "\n";

    return 0;
}
