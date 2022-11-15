#include<bits/stdc++.h>
using namespace std;

int main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size() ;
        bool ans = true ;
        ans &= n % 2 == 0 ;
        for(int i = 0 ; i < n/2 ; ++i) {
            ans &= s[i] != s[n - i - 1] ;
        }
        cout << (ans ? "YES" : "NO") << '\n' ;
    }

    return 0;
}
