#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		string s; cin >> s;
		set <string> S;
		for(int i = 0; i < (int) s.size(); i ++) {
			for(int j = i; j <= (int) s.size(); j ++) {
				string tmp = s;
				reverse(tmp.begin() + i, tmp.begin() + j);
				S.insert(tmp);
			}
		}	
		cout << S.size() << "\n";
	}	
	
	return 0;
}
