#include<bits/stdc++.h>
using namespace std ; 

int main() {

    ios::sync_with_stdio(0) ; 
    cin.tie(0) ; 

    int tests; 
    cin >> tests ; 

    while(tests--) {

        int n; 
        cin >> n ; 
        vector<long long> b(n) ; 
        for(auto &i : b) cin >> i ; 

        vector<long long> a(n) ; 
        long long sum = 0 ; 
        bool flag = 1 ; 

        for(int i = 0 ; i < n ; ++i) {
            if(b[i] % (i+2)) {
                flag = 0 ; 
                break ; 
            }
            a[i] = b[i]/(i+2) - sum;
            if(a[i] <= 0) {
                flag = 0 ; 
                break ; 
            } 
            sum += a[i] ; 
        }

        if(!flag) {
            cout << -1 << '\n' ; 
            continue ; 
        }
     
        for(int i = 0 ; i < n ; ++i) cout << a[i] << " " ; 
        cout << '\n' ; 
    }

    return 0 ; 
}
