//Time complexity - O(n) 

#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0) ;
    cin.tie(0); 
    int T; cin >> T ; 
    while(T--) {
        int n; cin >> n ;
        vector<int> v(n) ;
        for(auto &i : v) 
            cin >> i ; 
        int ans = 0 ; 
        for(int i = 1 ; i < n ; ++i) 
            ans = max(ans, abs(v[i] - v[i-1])) ; 
        cout << ans << '\n' ;
    }
}
