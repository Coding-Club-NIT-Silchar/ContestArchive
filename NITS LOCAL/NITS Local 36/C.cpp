#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
int d[MAX];
ll fact[MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    fact[0] = 1;
    for(int i = 1; i < MAX; i ++) fact[i] = (fact[i - 1] * i) % MOD;
    int n; cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        d[u] ++, d[v] ++;
    }
    ll ans = fact[d[1]];
    for(int i = 2; i <= n; i ++) ans = (ans * fact[d[i] - 1]) % MOD;
    cout << ans;
 
    
    return 0;
}
