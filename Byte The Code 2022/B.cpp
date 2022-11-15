#include<bits/stdc++.h>
using namespace std;

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for(int i = 0 ; i < n ; ++i) {
            cin >> a[i] ;
        }
        for(int i = 0 ; i < n ; ++i) {
            if(i < m) cin >> b[i] ;
            else b[i] = b[i - m] ;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        int mx = 0, mn = INT_MAX;
        for(int i = 0 ; i < n ; ++i) {
            mx = max(mx, a[i] + b[i]);
            mn = min(mn, a[i] + b[i]);
        }
        cout << mx - mn << '\n' ;
    }

    return 0;
}
