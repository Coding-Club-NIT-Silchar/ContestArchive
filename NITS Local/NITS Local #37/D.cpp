#include<bits/stdc++.h>
using namespace std;
 
const int N = 3e4 + 2;
bool is_not_prime[N];
int pf[N];
 
bool check(int n, string &s, int k) {
    for(int i = 1; i <= n; ++i) pf[i] = 0;
    for(int i = 1; i <= n; ++i) {
        pf[i] += pf[i - 1];
        if((s[i - 1] - '0') ^ (pf[i] & 1)) {
            if(i + k > n + 1) return false;
            pf[i] ++;
            pf[i + k] --;
        }
    }
    return true;
}
 
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    int ans = -1;
 
    for(int i = 2; i <= n; ++i) {
        if(!is_not_prime[i]) {
            if(check(n, s, i)) {
                ans = i;
                break;
            }
            for(int j = 2 * i; j <= n; j += i) {
                is_not_prime[j] = true;
            }
        }
    }
 
    cout << ans;
 
    return 0;
}
