#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7; 
const int N = 1e5 + 5 ; 
int dp[N] ; 

int main () {

    dp[1] = 1 ; 
    for(int i = 2 ; i < N ; ++i) {
        for(int j = 1 ; j * j <= i ; ++j) {
            if(i%j == 0) {
                dp[i] = (dp[i] + dp[i-j]) % mod ; 
                if(j*j != i) dp[i] = (dp[i] + dp[i-i/j]) % mod ; 
                // if j * j == i , i - j and i - i/j are same
                // but we should count it only once.
            }
        }
    }

    int t ; cin >> t ;
    while(t--) {
        int n; cin >> n ; 
        cout << dp[n] << endl ; 
    }

    return 0 ; 
}
