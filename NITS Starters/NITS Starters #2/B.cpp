#include<bits/stdc++.h>
using namespace std ; 

int main() {

    int tests; 
    cin >> tests ; 

    while(tests--) {

        int n; cin >> n ;
        n = abs(n) ; 
        int ans = 1e9 ;  
        for(int i = 0 ; i <= 2 * n ; ++i) {
            for(int j = 0 ; j <= i ; ++j) {
                if(i-j == n) {
                    ans = min(ans, __builtin_popcount(i) + __builtin_popcount(j)) ; 
                }
            }
        }
        cout << ans << '\n' ; 
    }

    return 0 ; 
}
