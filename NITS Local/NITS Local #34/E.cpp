#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
const int INF = 1e9;
string s[MAX];

// Trie
struct TrieNode {
    TrieNode *child[26];
    pair <int, int> minimum, secondMinimum;
    vector <int> idx;
    TrieNode() {
        for(int i = 0; i < 26; i ++) child[i] = NULL;
        minimum = secondMinimum = {INF, INF};
    }
};
TrieNode *root;
void add(string &s, int index) {
    TrieNode* cur = root;
    for(int i = 0; i < (int) s.size(); i ++) {
        int b = s[i] - 'a';
        if(!cur->child[b]) cur->child[b] = new TrieNode();
        cur = cur->child[b];
    }
    cur->idx.push_back(index);
}


// Kruskal MST
struct edge {
    int u, v;
    ll w;
    bool operator < (edge const & other) {
        return w < other.w;
    }
};
vector <edge> edges;
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
            join(e.u, e.v);
        }
    }
    return cost;
}

// Solution
void dfs(TrieNode *root, int len = 0) {
    int cnt = root->idx.size();
    if(cnt == 1) root->minimum = {len, root->idx[0]};
    else if(cnt >= 2) {
        root->minimum = {len, root->idx[0]};
        root->secondMinimum = {len, root->idx[1]};
    }
    for(int i = 0; i < 26; i ++) {
        if(!root->child[i]) continue;
        dfs(root->child[i], len + 1);
        auto p = root->child[i]->minimum;
        if(p.first < root->minimum.first) {
            root->secondMinimum = root->minimum;
            root->minimum = p;
        }
        else if(p.first < root->secondMinimum.first) {
            root->secondMinimum = p;
        }
        p = root->child[i]->secondMinimum;
        if(p.first < root->secondMinimum.first) {
            root->secondMinimum = p;
        }
    }
}

void addEdges(string &s, int u) {
    int l = s.size();
    TrieNode *cur = root;
    for(int i = 0; i <= l; i ++) {
        int v = INF, len = INF;
        if(cur->minimum.second != u) v = cur->minimum.second, len = cur->minimum.first;
        else v = cur->secondMinimum.second, len = cur->secondMinimum.first;
        if(v != INF) edges.push_back({u, v, len + l - 2 * i});
        if(i != l) cur = cur->child[s[i] - 'a'];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    root = new TrieNode();
    for(int i = 1; i <= n; i ++) {
        cin >> s[i];
        add(s[i], i);
    }
    dfs(root);
    for(int i = 1; i <= n; i ++) addEdges(s[i], i);
    cout << kruskal(n);

    return 0;
}
