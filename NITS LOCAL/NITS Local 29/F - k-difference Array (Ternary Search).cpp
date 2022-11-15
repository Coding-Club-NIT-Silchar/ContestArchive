/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
int n, k;
ll a[MAX];
ll f(ll x) {
	ll l = x, r = x + k, ret = 0;
	for(int i = 0; i < n; i ++) {
		if(a[i] >= l && a[i] <= r) continue;
		else if(a[i] < l) ret += l - a[i];
		else ret += a[i] - r;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		cin >> n >> k;
		for(int i = 0; i < n; i ++) cin >> a[i];	
		ll l = *min_element(a, a + n), r = *max_element(a, a + n);
		while(r - l > 2) {
			ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
	        ll f1 = f(m1), f2 = f(m2);
	        if(f1 < f2) r = m2;
	        else l = m1;
		}
		ll ans = f(l);
		for(ll i = l + 1; i <= r; i ++) ans = min(ans, f(i));
		cout << ans << "\n";
	}
	
	return 0;
}
