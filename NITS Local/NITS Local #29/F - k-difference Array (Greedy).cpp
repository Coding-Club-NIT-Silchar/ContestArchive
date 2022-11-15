/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
ll a[MAX], pre[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i ++) pre[i] = a[i] + pre[i - 1];
		ll ans = 1e18;
		for(int i = 1, j = 1; i <= n; i ++) {
			ll left = 1LL * i * a[i] - pre[i];
			while(j <= n && a[j] - a[i] <= k) j ++;
			left += pre[n] - pre[j - 1] - 1LL * (a[i] + k) * (n - j + 1);
			ans = min(ans, left);
		}
		for(int i = n, j = n; i > 0; i --) {
			ll right = pre[n] - pre[i - 1] - 1LL * (n - i + 1) * a[i];
			while(j > 0 && a[i] - a[j] <= k) j --;
			right += 1LL * j * (a[i] - k) - pre[j];
			ans = min(ans, right);
		}
		
		cout << ans << "\n";
	}	
	
	return 0;
}
