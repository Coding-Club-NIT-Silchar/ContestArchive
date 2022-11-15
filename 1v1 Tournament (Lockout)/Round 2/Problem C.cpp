#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    string s; cin >> s;
    int ans = 0;
    int l = 0, r = s.length() - 1;
    while(l <= r) {
        if(s[l] == s[r]) {
            l++;
            r--;
        }
        else {
            if(s[l] != 'x' && s[r] != 'x') {
                cout << -1;
                return 0;
            }
            if(s[l] == 'x') {
                l++;
                ans++;
                continue;
            }
            if(s[r] == 'x') {
                r--;
                ans++;
            }
        }
    }
    cout << ans;
}
