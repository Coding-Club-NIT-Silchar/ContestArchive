#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 1005;
ll dp[MAX];
void add(ll &a, ll b) {
	b %= MOD;
	a = (a + b) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		for(int i = 0; i <= n; i ++) dp[i] = 0;
		ll ans = 0;
		for(int i = 1; i <= n; i ++) {
			int x; cin >> x;
			dp[i] = 1;
			for(int j = 1; j < i; j ++) add(dp[i], dp[j]);
			if(x % 2 == 0) add(ans, dp[i]);
		}	
		cout << ans << "\n";
	}
	
	return 0;
}
