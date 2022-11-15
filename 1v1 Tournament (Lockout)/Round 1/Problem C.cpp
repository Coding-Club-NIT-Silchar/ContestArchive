#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    map <ll, int> f;
    for(int i = 0; i < n; i ++) {
        ll x; cin >> x;
        f[x] ++;
    }
    int ans = 0;
    for(ll i = (1LL << 31); i > 1; i >>= 1) {
        for(auto &p : f) {
            if(p.first * 2 == i) {
                ans += p.second / 2;
                p.second %= 2;
            }
            else if(f.find(i - p.first) != f.end()) {
                int mn = min(p.second, f[i - p.first]);
                ans += mn;
                p.second -= mn, f[i - p.first] -= mn;
            }
        }
    }
    cout << ans << "\n";
 
    return 0;
}
