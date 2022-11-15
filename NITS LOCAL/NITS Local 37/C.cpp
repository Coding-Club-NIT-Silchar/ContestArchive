#include<bits/stdc++.h>
using namespace std;
 
bool is_prime(long long n) {
    for(long long i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
 
int main() {
 
    long long x;
    cin >> x;
 
    long long l = x, r = x + 1;
    while(!is_prime(l)) -- l;
    while(!is_prime(r)) ++ r;
 
    cout << r - l;
 
    return 0;
}
