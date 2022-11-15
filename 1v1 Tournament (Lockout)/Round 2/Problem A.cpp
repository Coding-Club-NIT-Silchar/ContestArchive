#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string s; cin >> s;
    int n = s.size();
    assert(n >= 2 && n <= 200);
    n --;
    s = s.substr(0, n);
    while(true) {
        if(n & 1) {
            n --;
            s = s.substr(0, n);
        }
        else {
            if(s.substr(0, n / 2) == s.substr(n / 2)) {
                assert(n > 0 && n % 2 == 0);
                return cout << n, 0;
            }
            n --;
        }
    }

    return 0;
}
