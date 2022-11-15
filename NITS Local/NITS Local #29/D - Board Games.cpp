/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
ll fact[MAX];
void mul(ll &a, ll b) {
	b %= MOD;
	a = (a * b) % MOD;
}
void calculate() {
	fact[0] = 1;
	for(int i = 1; i < MAX; i ++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
}
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
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		
	calculate();
	ll n; cin >> n;
	ll ans = n;
	mul(ans, n * n + 1);
	mul(ans, modInverse(2));
	mul(ans, fact[n]);
	cout << ans;

	return 0;
}
