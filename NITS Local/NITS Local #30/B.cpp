#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n), q(n), r(n);
    for(int i = 0; i < n; ++i) {
        cin >> p[i] >> q[i] >> r[i];
    }
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int j = 0; j < n; ++j) {
            if(i != j) {
                int t = 0;
                t += p[i] < p[j];
                t += q[i] < q[j];
                t += r[i] < r[j];
                if(t > 1) ++ cnt;
            }
        }
        if(cnt == n - 1) {
            return cout << i + 1, 0;
        }
    }
    cout << -1;

    return 0;
}
