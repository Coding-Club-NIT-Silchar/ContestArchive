#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int> z_function(vector <int> s) {
    int n = s.size();
    vector <int> z(n, 0);
    for(int i = 1, l = 0, r = 0; i < n; i ++) {
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] <= s[i + z[i]]) z[i] ++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector <int> v(n + m + 1, INT_MAX);
    for(int i = 0; i < n; i ++) cin >> v[i];
    for(int i = 0; i < m; i ++) cin >> v[n + 1 + i];
    vector <int> pre = z_function(v);
    int cnt = 0;
    for(int i = n + 1; i < n + m + 1; i ++) cnt += pre[i] >= n;
    cout << cnt;
}
