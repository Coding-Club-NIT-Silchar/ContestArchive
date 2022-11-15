#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t --) {
        ll n, p;
        cin >> n >> p;
        ll z = (n + p) % 6;
        ll x = (n + p - z)  / 6;
        cout << x << " " << n - x - z << " " << z << "\n";
    }

    return 0;
}
