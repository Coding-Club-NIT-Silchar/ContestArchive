#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const int mod = 9999889 ;
int fact[mod] ;

int power(int a, int n) {
    if(n == 0) return 1 ;
    ll p = power(a, n/2) ;
    p = p * p % mod ;
    return n & 1 ? p * a % mod : p ;
}

int main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1 ;
    for(int i = 1 ; i < mod ; ++i) {
        fact[i] = fact[i-1] * 1ll * i % mod ;
    }

    int t; cin >> t; 
    while(t--) {
        ll a, n ; 
        cin >> a >> n ;
        a %= mod ;
        cout << (n >= mod ? 0 : power(a, n) * 1ll * fact[n] % mod) << '\n' ;
    }

    return 0;
}
