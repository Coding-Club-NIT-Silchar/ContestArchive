#include<bits/stdc++.h>
using namespace std;

int main () {

    int n, x; 
    cin >> n >> x; 
    int p[n], a[n] ; 

    for(int i = 0 ; i < n ; ++i) 
        cin >> p[i] ;  
    for(int i = 0 ; i < n ; ++i) 
        cin >> a[i] ; 

    long long final_price[n] ; 

    for(int i = 0 ; i < n ; ++i) {
        final_price[i] = p[i] + x * 1ll * a[i] ; 
    }

    long long maxPrice = 0, index = -1 ; 
    for(int i = 0 ; i < n ; ++i) {
        if(final_price[i] > maxPrice) {
            maxPrice = final_price[i] ; 
            index = i+1 ; 
        }
    }  

    cout << index ; 

    return 0 ; 
}
