#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		string s; cin >> s;
		vector <int> f(26, 0);
		for(char c : s) f[c - 'a'] ++;
		int n = s.size();
		ll ans = 1LL * n * (n - 1) / 2;
		for(int x : f) ans -= 1LL * x * (x - 1) / 2;
		cout << ans + 1 << "\n";
	}	
	
	return 0;
}
