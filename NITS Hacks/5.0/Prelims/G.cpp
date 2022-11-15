#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define int long long

int f(vector<pair<int, int>> &v) {
    if(v.empty()) return 0;
    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
        return a.second < b.second;
    });
    int ans = 1, r = v[0].second;
    for(int i = 1; i < (int)v.size(); ++i) {
        if(v[i].first > r) {
            ++ ans;
            r = v[i].second;
        }
    }
    return (int)v.size() - ans;
}

void solve() {
    int t;
    cin >> t;
    vector<pair<int, int>> v[2];
    while(t --) {
        int k, c;
        cin >> k >> c;
        -- c;
        int mn = 1e9, mx = 0;
        while(k --) {
            int x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        v[c].push_back({mn, mx});
    }
    cout << f(v[0]) + f(v[1]) << '\n';
}

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }

    return 0;
}
