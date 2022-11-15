#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
ll fact[MAX], invfact[MAX];
ll modExp(ll b, ll p) {
    ll res = 1;
    while(p > 0) {
        if(p & 1) res = (res * b) % MOD;
        b = (b * b) % MOD, p >>= 1;
    }
    return res;
}
ll modInverse(ll n) {
    return modExp(n, MOD - 2); 
}
void calculate() {
    fact[0] = 1;
    for(int i = 1; i < MAX; i ++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[MAX - 1] = modInverse(fact[MAX - 1]);
    for(int i = MAX - 2; i >= 0; i --) {
        invfact[i] = ((i + 1) * invfact[i + 1]) % MOD;
    }
}
ll nCr(ll n, ll r) {
    if(n < 0 || r < 0 || n < r) return 0;
    ll ret = fact[n];
    ret = (ret * invfact[n - r]) % MOD;
    ret = (ret * invfact[r]) % MOD;
    return ret;
}
void add(ll &a, ll b) {
    b %= MOD;
    a = (a + b) % MOD;
}
void mul(ll &a, ll b) {
    b %= MOD;
    a = (a * b) % MOD;
}
void sub(ll &a, ll b) {
    b %= MOD;
    a = (a - b) % MOD;
    a = (a + MOD) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    calculate();
    int X; cin >> X;
    ll num = X, den = 1;
    for(int len = 2; len <= X; len ++) {
        add(den, nCr(X - 1, X - len));
        ll cur = 0;
        for(int a = 1; a <= X; a ++) {
            if(X - (a - 1) * len - 1 <= 0 || X - a * len < 0) break;
            add(cur, 1LL * a * nCr(X - (a - 1) * len - 1, len - 1));
            sub(cur, 1LL * a * nCr(X - a * len - 1, len - 1));
        }
        add(num, cur);
    }
    mul(num, modInverse(den));

    cout << num;

    return 0;
}
