#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int ans = 2 * n;
    for(int i = 1; i <= n; i ++) {
        if(t.substr(0, i) == s.substr(n - i, i)) ans = min(ans, 2 * n - i);
    }
    cout << ans;
 
    return 0;
}
