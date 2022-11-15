#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7 ; 

int add(int x, int y) { return (x + y > mod ? x + y - mod : x + y); }
int mul(int x, int y) { return (long long) x * y % mod; }

struct matrix {
    int n ; 
    vector<vector<int> > a;
    matrix(int _n) {
        n = _n ; 
        a.resize(n, vector<int>(n)) ; 
    }
    matrix operator * (const matrix& other) {
        matrix p(n);
        for(int i = 0 ; i < n; ++i) 
            for(int j = 0 ; j < n ; ++j) 
                for(int k = 0 ; k < n ; ++k) 
                    p.a[i][k] = add(p.a[i][k], mul(a[i][j], other.a[j][k])) ; 
        return p ; 
    }
};

matrix expo_power(matrix a, long long k, int n) {
    matrix res(n); 
    for(int i = 0 ; i < n ; ++i) 
        res.a[i][i] = 1 ; // unit matrix
    while(k) {
        if(k&1) res = res * a ; 
        a = a * a ;
        k >>= 1 ; 
    }
    return res; 
}

const int L = 100;

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    // cin >> T;
    int cnt = 0;
    int sum = 0;
    while(T --) {
        ++ cnt;
        if(cnt > 500) break;
        int d, n;
        cin >> d >> n;
        sum += d;
        vector<int> f(L + 1);
        for(int i = 0; i < d; ++i) {
            int x;
            cin >> x;
            if(x > L) continue;
            f[x] ++;
        }
        vector<int> dp(L + 1);
        dp[0] = 1;
        for(int i = 1; i <= L; ++i) {
            for(int j = 1; i - j >= 0 && j <= L; ++j) {
                dp[i] = (dp[i] + dp[i - j] * f[j] % mod) % mod;
            }
        }
        if(n <= L) {
            cout << dp[n] << '\n';
        }
        else {
            matrix m(L);
            for(int i = 0; i < L; ++i) m.a[0][i] = f[i + 1];
            for(int i = 1; i < L; ++i) m.a[i][i - 1] = 1;
            matrix res = expo_power(m, n - L, L);
            int ans = 0;
            for(int i = 0; i < L; ++i) {
                ans = (ans + mul(res.a[0][i], dp[L - i])) % mod;
            }
            cout << ans << '\n';
        }
    }
    assert(1 <= sum && sum <= 2e5);

    return 0;
}
