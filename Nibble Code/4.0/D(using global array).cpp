#include<bits/stdc++.h>
using namespace std;

using ll = long long; 
const int mxN = 1e7 + 100;

int c[mxN];
int f(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum ;
}


int main() {

    ios::sync_with_stdio(0) ; 
    cin.tie(0) ;

    int T; 
    cin >> T ; 
    while(T--) {
        int n; 
	cin >> n ;
        int a[n] ; 
        for(int i = 0 ; i < n ; i++) 
            cin >> a[i] ;
        for(int i = 0 ; i < n ; i++) {
            int s = a[i] + f(a[i]);
            c[s] ++ ;
        }

        ll ans = 0 ;
        for(int i = 0 ; i < n ; i++) {
            int s = a[i] + f(a[i]);
            if(c[s] > 0) {
                ans += c[s]* 1LL * (c[s]-1) / 2 ; // if you don't want to multiply by 1LL 
                c[s]=0;                           // you need to declare c[] as long long 
                                                  // to avoid overflow
            }
        }
        cout << ans << endl;
    }
    return 0 ; 
}
