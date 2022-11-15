#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
bool dp[MAX];
int main() {
    int n, s;
    cin >> n >> s;
    dp[0] = 1;
    vector <int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    if(sum < s) return cout << -1, 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 1; i ++) {
        for(int j = MAX - 1; j >= a[i]; j --) dp[j] |= dp[j - a[i]];
    }
    int ans = 0;
    for(int i = 0; i < s; i ++) {
        if(dp[i]) ans = max(ans, i + a[n - 1] - s);
    }
    cout << ans << "\n";
}
