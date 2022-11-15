#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		int n, m;
		cin >> n >> m;
		set <int> s1, s2;
		for(int i = 0; i < m; i ++) {
			int r, c;
			cin >> r >> c;
			if(r == 1) s1.insert(c);
			else s2.insert(c);
		}	
		int ans = 1;
		for(int x : s1) {
			for(int y = x - 1; y <= x + 1; y ++) {
				if(s2.find(y) != s2.end()) ans = 0;
			}
		}
		cout << ans << "\n";
	}	
	
	return 0;
}
