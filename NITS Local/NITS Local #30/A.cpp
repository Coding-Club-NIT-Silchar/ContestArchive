#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    string ans;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    for(int i = 0; i < (int)s.size(); ++i) {
        ans += (s[i] == t[i] ? '0' : '1');
    }
    sort(ans.begin(), ans.end(), greater<char>());
    cout << ans;

    return 0;
}
