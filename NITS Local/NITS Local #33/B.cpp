#include<bits/stdc++.h>
using namespace std ; 

int main() {

    int t ; cin >> t ;
    while(t--) {
        int n; cin >> n ; 
        n *= 2 ; 
        n += 3 ;

        bool flag = 1 ; 
        for(int i = 2 ; i * i <= n ; ++i) 
            if(n%i == 0) {
                flag = 0 ; 
                break  ;
            }

        if(!flag) cout << -1 << '\n' ; 
        else {
            cout << n << " " << 2 << '\n' ; 
        }
    }

    return 0 ; 
}
