#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        multiset<long long> m;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            m.insert(x);
        }
        while(!m.empty()) {
            long long x = *m.begin();
            m.erase(m.begin());
            if(!m.empty() && *m.begin() == x) {
                m.erase(m.begin());
                m.insert(2 * x);
            }
            else ++ ans;
        }
        cout << ans << '\n';
    }
 
    return 0;
}
