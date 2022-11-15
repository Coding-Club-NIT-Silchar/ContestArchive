#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
 
signed main() {
 
   ios :: sync_with_stdio(0);
   cin.tie(0);
 
   int T;
   cin >> T;
   while(T --) {
       int n;
       cin >> n;
       ld ans = 0;
       ld p = 1;
       for(int i = 1; i <= n; ++i) {
           ld x;
           cin >> x;
           ans += i * x * p;
           p *= (1 - x);
       }
       cout << fixed << setprecision(6) << ans << '\n';
   }
 
   return 0;
}
