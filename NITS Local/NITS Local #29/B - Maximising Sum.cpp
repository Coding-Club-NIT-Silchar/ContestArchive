/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vector <ll> a(n);
	for(ll &x : a) cin >> x;
	ll sum = accumulate(a.begin(), a.end(), 0LL), cur = 0;
	ll ans = sum;
	for(int i = 0; i < n; i ++) {
		cur += a[i], sum -= a[i];
		ans = max(ans, sum - cur);
	}	
	cout << ans;
	
	return 0;
}
