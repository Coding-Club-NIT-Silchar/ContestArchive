/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
ll dp[5][MAX];
void add(ll &a, ll b) {
	b %= MOD;
	a = (a + b) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	dp[0][0] = 1;
	for(int i = 1; i < MAX; i ++) {
		for(int j = 0; j < 5; j ++) add(dp[0][i], dp[j][i - 1]);
		add(dp[1][i], dp[0][i - 1] + dp[3][i - 1]);
		add(dp[2][i], dp[0][i - 1]);
		add(dp[3][i], dp[0][i - 1] + dp[1][i - 1]);
		add(dp[4][i], dp[0][i - 1]);
	}	
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		ll ans = 0;
		for(int i = 0; i < 5; i ++) add(ans, dp[i][n]);
		ans = (ans - 1 + MOD) % MOD;
		cout << ans << "\n";
	}
	
	return 0;
}
