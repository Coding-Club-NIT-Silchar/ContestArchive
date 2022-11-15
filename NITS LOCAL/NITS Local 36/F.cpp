/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAXV = 121;
const int MAX = 1e5 + 10;
vector <ll> primes;
void sieve() {
	bool prime[MAXV];
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i * i < MAXV; i ++) {
		if(prime[i]) {
			for(int j = i * i; j < MAXV; j += i) prime[j] = false;
		}
	}
	for(int i = 0; i < MAXV; i ++) if(prime[i]) primes.push_back(i);
}
ll getMask(ll x) {
	ll mask = 0, bit = 0;
	for(ll p : primes) {
		int cnt = 0;
		while(x % p == 0) {
			x /= p;
			cnt ^= 1;
		}
		if(cnt) mask |= 1LL << bit;
		bit ++;
	}
	return mask;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	sieve();	
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		map <ll, pair <ll, ll>> mp;
		mp[0] = {0, 1};
		ll cur = 0;
		double ans = 0;
		for(int i = 1; i <= n; i ++) {
			ll x; cin >> x;
			cur ^= getMask(x);
			if(mp.find(cur) == mp.end()) mp[cur] = {i, 1};
			else {
				auto p = mp[cur];
				ans += 1LL * i * p.second - p.first;
				mp[cur] = {p.first + i, p.second + 1};
			}
		}
		ans *= 2;
		ans /= (1LL * n * (n + 1));
		cout << setprecision(10) << fixed << ans << "\n";
	}
	
	return 0;
}
