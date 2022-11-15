#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n; cin >> n;
    if(n == 1) return cout << 0, 0;
    ll ans = 0;
    for(ll i = 2, x = n; i * i <= x; i ++) {
        ll cnt = 0;
        while(n % i == 0) {
            cnt ++;
            n /= i;
        }
        for(ll j = 1;; j ++) {
            if(j <= cnt) {
                ans ++;
                cnt -= j;
            }
            else break;
        }
    }
    if(n > 1) ans ++;
    cout << ans;

    return 0;
}
