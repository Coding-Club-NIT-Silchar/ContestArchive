/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int sign(ll x) {
	if(!x) return 0;
	return (x > 0 ? 1 : -1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	ll u, x[n], v[n];
	cin >> u;
	for(int i = 0; i < n; i ++) cin >> x[i] >> v[i];
	int left = 0, right = 0;
	for(int i = 0; i < n; i ++) {
		ll speed = -(v[i] + u), dis = x[i];
		if(sign(speed) == sign(dis)) left += (dis % speed == 0);
	}
	for(int i = 0; i < n; i ++) {
		ll speed = u - v[i], dis = x[i];
		if(sign(speed) == sign(dis)) right += (dis % speed == 0);
	}
	cout << max(left, right);	
	
	return 0;
}
