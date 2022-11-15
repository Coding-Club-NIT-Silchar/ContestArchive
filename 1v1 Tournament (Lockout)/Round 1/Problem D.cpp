#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
map <pair <string, string>, int> solve(string s) {
    map <pair <string, string>, int> ret;
    int n = s.size();
    for(int msk = 0; msk < (1 << n); msk ++) {
        string a = "", b = "";
        for(int i = 0; i < n; i ++) {
            if((msk >> i) & 1) a += s[i];
            else b += s[i];
        }
        ret[{a, b}] ++;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    string s; cin >> s;
    auto m1 = solve(s.substr(0, n)), m2 = solve(s.substr(n));
    ll ans = 0;
    for(auto p : m1) {
        string a = p.first.first, b = p.first.second;
        reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
        ans += 1LL * p.second * m2[{b, a}];
    }
    cout << ans << "\n";
 
    return 0;
}
