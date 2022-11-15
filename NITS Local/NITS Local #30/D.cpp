#include<bits/stdc++.h>
using namespace std;

#define int long long

struct d {
    int a, b, c, id;
    bool operator < (const d &other) {
        int t = 0;
        if(a < other.a) ++ t;
        if(b < other.b) ++ t;
        if(c < other.c) ++ t;
        if(t > 1) return 1;
        return 0;
    }
};

signed main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<d> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].id = i + 1;
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < n; ++i) {
        int t = 0;
        t += v[0].a < v[i].a;
        t += v[0].b < v[i].b;
        t += v[0].c < v[i].c;
        if(t < 2) {
            return cout << -1, 0;
        }
    }
    cout << v[0].id;

    return 0;
}
