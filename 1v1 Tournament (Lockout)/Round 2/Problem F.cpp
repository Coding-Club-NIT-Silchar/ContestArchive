#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 3005;
const ll MOD = 998244353;
void add(ll &a, ll b) {
    b %= MOD;
    a = (a + b) % MOD;
}
ll dp[MAX][MAX];
int a[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, s; cin >> n >> s;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int sum = 0; sum <= s; sum ++) {
            add(dp[i][sum], 2 * dp[i - 1][sum]);
            if(sum - a[i] >= 0) add(dp[i][sum], dp[i - 1][sum - a[i]]);
        }
    }
    cout << dp[n][s];

    return 0;
}
