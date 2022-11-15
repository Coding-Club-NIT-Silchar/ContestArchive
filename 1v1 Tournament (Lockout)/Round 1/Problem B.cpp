#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, x; cin >> n >> x;
    vector <int> a(n);
    for(int &y : a) cin >> y;
    ll ans = 0;
    for(int i = 0; i < n - 1; i ++) {
        if(a[i] + a[i + 1] <= x) continue;
        ans += a[i] + a[i + 1] - x;
        int mn = min(a[i] + a[i + 1] - x, a[i + 1]);
        a[i + 1] -= mn;
    }
    cout << ans;
 
    return 0;
}
