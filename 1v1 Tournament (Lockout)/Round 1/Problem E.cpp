#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 5005 * 5005;
ll dp[MAX];
ll knapsack(int total, vector <int> w, vector <int> v) {
    int n = w.size();
    for(int j = 0; j <= total; j ++) dp[j] = j;
    for(int j = 0; j <= total; j ++) {
        for(int i = 0; i < n; i ++) {
            if(j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    ll ret = 0;
    for(int i = 0; i <= total; i ++) ret = max(ret, dp[i]);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    int g1, s1, b1; cin >> g1 >> s1 >> b1;
    int g2, s2, b2; cin >> g2 >> s2 >> b2;
    ll m = knapsack(n, {g1, s1, b1}, {g2, s2, b2});
    ll ans = knapsack(m, {g2, s2, b2}, {g1, s1, b1});
    cout << ans;

    return 0;
}
