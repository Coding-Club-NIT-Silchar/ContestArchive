#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
ll C[MAX], pre[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; ll k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> C[i];
        pre[i] = pre[i - 1] + C[i];
    }
    ll cur = 0;
    int ans = 0;
    for(int l = 1, r = 0; l <= n; l ++) {
        while(r < n && cur + 1LL * (r - l + 2) * C[r + 1] <= k) {
            r ++;
            cur += 1LL * (r - l + 1) * C[r];
        }
        ans = max(ans, r - l + 1);
        cur -= pre[r] - pre[l - 1];
    }
    cout << ans;

    return 0;
}
