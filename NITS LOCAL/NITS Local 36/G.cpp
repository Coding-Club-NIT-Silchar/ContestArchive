#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    return l + (rng() % (r - l + 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <ll> s(n), r(n);
    for(ll &x : s) cin >> x;
    for(ll &x : r) cin >> x;
    vector <ll> candidates;
    for(int i = 0; i < min(n, 30); i ++) {
        int idx = rand(0, n-1);
        ll R = r[idx], S = s[idx];
        candidates.push_back(S);
        for(ll d = 1; d * d <= R; d ++) {
            if(R % d == 0) {
                candidates.push_back(S + d);
                if(d * d != R) candidates.push_back(S + R / d);
            }
        }
    }
    sort(candidates.begin(), candidates.end());
    candidates.resize(distance(candidates.begin(), unique(candidates.begin(), candidates.end())));
    bool flag = false;
    for(ll K : candidates) {
        int cnt = 0;
        for(int i = 0; i < n; i ++) {
            if(K > s[i] && r[i] % (K - s[i]) == 0) cnt ++;
        }
        if(cnt >= n - n / 2) {
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES" : "NO");
}
