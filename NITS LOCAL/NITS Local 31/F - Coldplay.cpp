#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
void add(ll &a, ll b) {
    b %= MOD;
    a = (a + b) % MOD;
}
void mul(ll &a, ll b) {
    b %= MOD;
    a = (a * b) % MOD;
}
ll modExp(ll b, ll p) {
    ll res = 1;
    while(p > 0) {
        if(p & 1) res = (res * b) % MOD;
        b = (b * b) % MOD, p >>= 1;
    }
    return res;
}
ll modInverse(ll n) {
    return modExp(n, MOD - 2); 
}
const int MAXN = 1e5 + 10;
const int MAXK = 51;
ll dp[MAXN][MAXK];
vector <int> g[MAXN];
int n, k, a;
void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    vector <int> nodes;
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        nodes.push_back(v);
    }
    int sz = nodes.size();
    if(!sz) return;
    vector <vector <ll>> tdp(sz, vector <ll> (k + 1, 0));
    for(int i = 0; i <= k; i ++) tdp[0][i] = dp[nodes[0]][i];
    for(int i = 1; i < sz; i ++) {
        for(int pc = 0; pc <= k; pc ++) {
            for(int cc = 0; cc <= k; cc ++) {
                if(cc + pc > k) break;
                add(tdp[i][cc + pc], tdp[i - 1][pc] * dp[nodes[i]][cc]);
            }
        }
    }
    for(int i = 2; i <= k; i ++) dp[u][i] = tdp[sz - 1][i - 1];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> k >> a;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(a, 0);
    ll den = 0;
    for(int i = 1; i <= n; i ++) add(den, dp[i][k]);
    ll num = dp[a][k];
    ll ans = num;
    mul(ans, modInverse(den));
    cout << ans << "\n";

    return 0;
}

