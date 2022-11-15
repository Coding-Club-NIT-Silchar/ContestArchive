#include<bits/stdc++.h>
using namespace std;

#define int long long

struct data {
    int id;
    int a[3];
    bool operator < (const data &other) {
        int t = 0;
        for(int i = 0; i < 3; ++i) {
            t += a[i] < other.a[i];
        }
        if(t > 1) return 1;
        return 0;
    }
};

signed main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<data> v(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> v[i].a[j];
        }
        v[i].id = i + 1;
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < n; ++i) {
        int t = 0;
        for(int j = 0; j < 3; ++j) {
            t += v[0].a[j] < v[i].a[j];
        }
        if(t < 2) {
            return cout << -1, 0;
        }
    }
    cout << v[0].id;

    return 0;
}
