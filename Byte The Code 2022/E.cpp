#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
 
const int mod = 998244353;
const int N = 6e5 + 1; 

inline int add(int a, int b) {return (a + b >= mod ? a + b - mod : a + b);}
inline int mul(int a, int b) {return a * 1ll * b % mod;}
 
int power[N];
 
int main() {
 
    ios :: sync_with_stdio(0);
    cin.tie(0);

    power[0] = 1;
    for(int i = 1 ; i < N ; ++i) {
        power[i] = mul(power[i - 1], 2);
    }
 
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n + 1), y(n + 1), pf(n + 1);
        for(int i = 1; i <= n; ++i) {
            cin >> x[i];
        }
        for(int i = 1; i <= n; ++i) {
            cin >> y[i];
        }
        int sum = 0, ans = m % mod;
        for(int i = 1; i <= n && x[i] < m; ++i) {
            sum = mul(sum, 2) ;
            sum = add(sum, x[i] - x[i - 1]);
            pf[i] = sum;
            int j = upper_bound(x.begin(), x.end(), y[i]) - x.begin();
            int cur_uni = sum - mul(power[i - j], pf[j]);
            if(cur_uni < 0) cur_uni += mod;
            cur_uni = add(cur_uni, mul(power[i - j], x[j] - y[i]));
            ans = add(ans, cur_uni);
        }
        cout << ans << '\n' ;
    }
 
    return 0;
}
