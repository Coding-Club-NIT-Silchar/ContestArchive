#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

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
            bit[x] += val;
    }

    T _query(int x) {
            T sum = 0;
             for(; x > 0; x -= x&-x)
                   sum += bit[x];
            return sum;
    }

    T query(int l,int r) {
        return _query(r) - _query(l-1) ;
    }
};

int f(vector<int> &a, int idx) {
    int n = a.size();
    BIT<int> bit(n);
    int ans = 0;
    for(int i = idx; i < n; i += 2) {
        ans += bit.query(a[i], n);
        bit.update(a[i], 1);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    for(int i = 0; i < n; ++i) {
        if(a[i] % 2 != (i + 1) % 2) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << f(a, 0) + f(a, 1) << '\n';
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
