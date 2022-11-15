#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
 
    int n, r;
    cin >> n >> r;
    
    int gr = __gcd(r, n);
    int gb = __gcd(n - r, n);
 
    cout << r / gr << " " << n / gr << '\n' ;
    cout << (n - r) / gb << " " << n / gb << '\n' ;
 
    return 0;
}
