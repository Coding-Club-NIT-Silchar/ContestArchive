#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
struct edge {
    int u, v;
    ll w;
    bool operator < (edge const & other) {
        return w < other.w;
    }
};
vector <edge> edges, result;
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
ll kruskal(int n) {
    ll cost = 0;
    for(int i = 1; i <= n; i ++) init(i);
    sort(edges.begin(), edges.end());
    for(edge e : edges) {
        if(find(e.u) != find(e.v)) {
            cost += e.w;
            result.push_back(e);
            join(e.u, e.v);
        }
    }
    return cost;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector <pair <int, int>> x, y;
    for(int i = 1; i <= n; i ++) {
        int a, b; cin >> a >> b;
        x.push_back({a, i});
        y.push_back({b, i});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i = 1; i < n; i ++) {
        int a = x[i - 1].second, b = x[i].second;
        int w = x[i].first - x[i - 1].first;
        edges.push_back({a, b, w});
    }
    for(int i = 1; i < n; i ++) {
        int a = y[i - 1].second, b = y[i].second;
        int w = y[i].first - y[i - 1].first;
        edges.push_back({a, b, w});
    }
    cout << kruskal(n);

    return 0;
}
