#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		string a, b;
		cin >> a >> b;
		vector <int> f1(26, 0), f2(26, 0);
		for(char c : a) f1[c - 'a'] ++;
		for(char c : b) f2[c - 'a'] ++;
		int ans = 1;
		for(int i = 0; i < 26; i ++) {
			if(f1[i] && !f2[i]) ans = 0;
		}
		cout << ans << "\n";
	}
	
	return 0;
}
