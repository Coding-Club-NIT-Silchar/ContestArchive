#include<bits/stdc++.h>
using namespace std ; 

int main() {

    int n; 
    string s ; 
    cin >> n >> s; 

    int frequency[26] = {} ; 
    
    for(auto i : s) 
        frequency[i-'a'] ++ ; 

    int ans = 0 ; 

    for(int i = 0 ; i < 26 ; ++i) {
        if(frequency[i] > 1) 
            ans += frequency[i] ; 
    }

    cout << ans ; 

    return 0 ; 
}
