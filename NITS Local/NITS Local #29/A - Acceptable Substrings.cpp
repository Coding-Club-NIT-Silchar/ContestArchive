/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
bool acceptable(string s) {
	int cnt = 0;
	for(char c : s) if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt ++;
	return (cnt == (int) s.size() || cnt == 0);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	string s; cin >> s;
	vector <string> ans;
	for(int i = 0; i < n; i ++) {
		for(int len = 1; i + len - 1 < n; len ++) {
			if(acceptable(s.substr(i, len))) ans.push_back(s.substr(i, len));
		}
	}	
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x << "\n";
	
	return 0;
}
