#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, m, l;
    cin >> n >> m >> l;
    string s; cin >> s;
    pair <int, int> x, y;
    int curX = 0, curY = 0;
    for(int i = 0; i < l; i ++) {
        if(s[i] == 'U') curY --;
        else if(s[i] == 'D') curY ++;
        else if(s[i] == 'L') curX --;
        else if(s[i] == 'R') curX ++;
        x.first = min(x.first, curX);
        x.second = max(x.second, curX);
        y.first = min(y.first, curY);
        y.second = max(y.second, curY);
    }
    int dx = x.second - x.first + 1;
    int dy = y.second - y.first + 1;
    if(dx > m || dy > n) return cout << 0, 0;
    ll ans = m - dx + 1;
    ans *= n - dy + 1;
    cout << ans;
}
