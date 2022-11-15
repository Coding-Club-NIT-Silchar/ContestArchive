#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(2);
    c[0] = count(s.begin(), s.end(), '0');
    c[1] = n - c[0];
    string ans = s;
    int res = 0;
    for(int len = n - 1; len; -- len) {
        int x = n - len;
        if(n % x == 0) {
            bool ok = 1;
            for(int j = 0; j < 2; ++j) ok &= (c[j] % (n / x) == 0);
            if(ok) {
                int itr = 0;
                for(int j = 0; j < x; ++j) {
                    if(c[itr] == 0) ++ itr;
                    for(int k = j; k < n; k += x) {
                        ans[k] = '0' + itr;
                        c[itr] --;
                    }
                }
                res = len;
                break;
            }
        }
        else {
            int r = n % x;
            bool ok = 0;
            for(int c0 = 0; c0 <= r; ++c0) {
                int c1 = r - c0;
                if(c0 > c[0] || c1 > c[1]) continue;
                if((c[0] - c0) % (n / x) || (c[1] - c1) % (n / x)) continue;
                if(c1 > (c[1] - c1) / (n / x) || c0 > (c[0] - c0) / (n / x)) continue;
                ok = 1;
                ans.assign(n, '0');
                for(int i = 0; i < c1; ++i) {
                    if(!c[1]) break;
                    for(int j = i; j < n; j += x) {
                        ans[j] = '1';
                        -- c[1];
                    }
                }
                for(int i = x - 1; i >= c1; --i) {
                    if(!c[1]) break;
                    for(int j = i; j < n; j += x) {
                        ans[j] = '1';
                        -- c[1];
                    }
                }
            }
            res = len;
            if(ok) break;
        }
    }
    cout << ans << '\n';
}

signed main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T --) {
        solve();
    }

    return 0;
}
