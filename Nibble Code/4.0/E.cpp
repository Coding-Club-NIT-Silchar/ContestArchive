#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5 ; 
int spf[N] ; // stores the smallest prime factor of each integer < N

int main () {

    ios::sync_with_stdio(0) ; // for fast input 
    cin.tie(0) ; 

    for(int i = 1 ; i < N ; ++i) 
        spf[i] = i ; 
    
    for(int i = 2 ; i < N ; ++i) {
        if(spf[i] == i) { // this condition will be satisfied only for prime numbers 
            for(int j = 2 * i ; j < N ; j += i) { // we increment j by i, so we traverse only the 
                spf[j] = min(spf[j], i) ;         // multiples of i
            }
        }
    }

    int n, q; cin >> n >> q; 
    int a[n+1], d[n+1] ; 
    long long pf[n+1] = {} ; // make sure to initialize with 0
    
    for(int i = 1 ; i <= n ; ++i) {
        cin >> a[i] ; 
        d[i] = spf[a[i]] ;
        pf[i] = pf[i-1] + d[i] ; // making the prefix sum array
    }

    while(q--) {
        int l, r; 
        cin >> l >> r; 
        cout << pf[r] - pf[l-1] << '\n'; 
    }

    return 0 ; 
}
