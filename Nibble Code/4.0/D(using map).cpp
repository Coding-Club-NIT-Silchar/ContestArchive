#include<bits/stdc++.h>
using namespace std;

int f(int x) {
    int sum = 0 ; 
    while(x) {
        sum += x % 10 ; 
        x /= 10 ; 
    }
    return sum ; 
}

int main () {

    int T ; 
    cin >> T ; 
    while(T --) {

        int n; 
        cin >> n ; 
        map<int,int> m ; 
        
        int a[n] ; 
        for(int i = 0 ; i < n ; ++i) {
        	cin >> a[i] ; 
        	int s = a[i] + f(a[i]) ; 
        	m[s] ++ ; 
        }

        long long ans = 0 ; 
        for(auto [x,y] : m) {
            ans += y * 1ll * (y-1) / 2 ; // multiplied with 1ll to avoid overflow
        }

        cout << ans << '\n' ; 
    }

    return 0 ; 
}
