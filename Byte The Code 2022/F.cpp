#include<bits/stdc++.h>
using namespace std;
 
const int N = 1025;
const int K = 11;
int dp[N][1 << K];
 
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
 
    for(int i = 1 ; i < N ; ++i){
        for(int j = 0 ; j < (1 << K) ; ++j){
            vector<bool> s(N, false);
            for(int k = 0 ; (1 << k) <= i ; ++k){
                if((j >> k)&1) {
                    s[dp[i - (1 << k)][j ^ (1 << k)]] = true;
                }
            }
            for(int k = 0 ; k < N ; ++k){
                if(!s[k]){
                    dp[i][j] = k;
                    break;
                }
            }
        }
    }
 
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 0;
        for(int i = 0 ; i < n; ++i) {
            int x; cin >> x;
            ans ^= dp[x][(1 << K) - 1];
        }
        cout << (ans ? "Hinata" : "Kageyama") << '\n' ;
    }
 
    return 0;
}
