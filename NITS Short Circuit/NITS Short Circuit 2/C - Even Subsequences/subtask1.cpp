#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		vector <int> v(n);
		for(int &x : v)	 cin >> x;
		int ans = 0;
		for(int i = 1; i < (1 << n); i ++) {
			for(int bit = n - 1; bit >= 0; bit --) {
				if((i >> bit) & 1) {
					if(v[bit] % 2 == 0) ans ++;
					break;
				}
			}
		}
		cout << ans << "\n";
	}	
	
	return 0;
}
