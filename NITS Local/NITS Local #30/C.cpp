#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    int mx = -1e18, sum = 0;
    bool st = 0;
    for(int i = 0; i < n; ++i) {
        if(b[i]) sum = max(a[i], sum + a[i]), st = 1;
        else if(st) sum += a[i];
        mx = max(mx, sum);
    }
    cout << mx;

    return 0;
}
