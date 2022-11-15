#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9;

void solve() {
    int n, l; cin >> n >> l;
    int a[n] {0};
    for(int i = 0; i < n; i ++) {
        string s; cin >> s;
        for(int j = 0; j < l; j ++) {
            a[i] += (s[j] == 'a');
        }
    }   

    sort(a, a + n);

    int ans = INF;
    for(int i = 1; i < n; i ++) {
        ans = min(ans, a[i] - a[i - 1]);
    }

    cout << l * l - ans * ans << '\n';
}

signed main() {
    int t; cin >> t;
    while(t --) {
        solve();
    }
}
