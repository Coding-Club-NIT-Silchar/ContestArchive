#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll modExp(ll b, ll p) {
	ll res = 1;
	while(p > 0) {
		if(p & 1) res = (res * b) % MOD;
		b = (b * b) % MOD, p >>= 1;
	}
	return res;
}
void add(ll &a, ll b) {
	b %= MOD;
	a = (a + b) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		ll ans = 0;
		for(int i = 1; i <= n; i ++) {
			int x; cin >> x;
			if(x % 2 == 0) add(ans, modExp(2, i - 1));
		}	
		cout << ans << "\n";
	}
	
	return 0;
}
