#include<bits/stdc++.h>
using namespace std;

#define int long long

template <typename T> 
struct BIT {
    int n; 
    vector<T> bit;
    
    BIT(int x) {
        n = x; 
        bit.resize(n+5) ;
    }

    void update(int x, T val) {
          for(; x <= n; x += x&-x)
            bit[x] = max(bit[x], val);
    }

    T _query(int x) {
            T sum = 0;
             for(; x > 0; x -= x&-x)
                   sum = max(sum, bit[x]);
            return sum;
    }

    T query(int l,int r) {
        return _query(r) - _query(l-1) ;
    }
};

const int mod = 1e9 + 7;

signed main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> comp, m;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
        comp[i];
    }
    int c = 1;
    for(auto &[x, y] : comp) {
         y = c ++;
    }

    BIT<int> bit(c);

    for(int i = 0; i < n; ++i) {
        int v = comp[a[i]];
        int sum = bit.query(1, v - 1);
        bit.update(v, a[i] + sum);
        m[a[i]] = max(m[a[i]], sum + a[i]);
    }

    cout << bit.query(1, c) << '\n';
    int ans = 0;
    for(auto [x, y] : m) {
        ans = (ans + x * y % mod) % mod;
    }

    cout << ans;

    return 0;
}
