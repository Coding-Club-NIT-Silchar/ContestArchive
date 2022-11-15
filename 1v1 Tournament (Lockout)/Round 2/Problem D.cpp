#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 3e5 + 10;
ll pref[MAX], suff[MAX], a[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= 3 * n; i ++) cin >> a[i];
    multiset <int> ms; ll cur = 0;
    for(int i = 1; i <= n; i ++) {
        ms.insert(a[i]);
        cur += a[i];
    }
    pref[n] = cur;
    for(int i = n + 1; i <= 2 * n; i ++) {
        ll x = *ms.begin();
        if(a[i] > x) {
            ms.erase(ms.begin());
            cur += a[i] - x;
            ms.insert(a[i]);
        }
        pref[i] = cur;
    }
    cur = 0; ms.clear();
    for(int i = 3 * n; i > 2 * n; i --) {
        cur += a[i];
        ms.insert(a[i]);
    }
    suff[2 * n + 1] = cur;
    for(int i = 2 * n; i > n; i --) {
        ll x = *prev(ms.end());
        if(x > a[i]) {
            ms.erase(ms.find(x));
            cur += a[i] - x;
            ms.insert(a[i]);
        }
        suff[i] = cur;
    }
    ll ans = -1e18;
    for(int i = n; i <= 2 * n; i ++) ans = max(ans, pref[i] - suff[i + 1]);
    cout << ans;

    return 0;
}
