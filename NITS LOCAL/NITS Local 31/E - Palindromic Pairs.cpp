#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MAX = 1e5 + 10;
ll st[MAX], en[MAX];
vector <ll> manacher(string &s) {
    string s1 = "@";
    for(ll i = 0; i < (ll) s.size(); i ++) {
        s1 += s[i]; s1 += "#";
    }
    s1.back() = '&';
    ll sz = s1.size() - 1, l = 0, r = 0;
    vector <ll> m(sz, 0);
    for(ll i = 1; i < sz; i ++) {
        if(i != 1) m[i] = min(r - i, m[r - i + l]);
        while(s1[i - m[i] - 1] == s1[i + m[i] + 1]) m[i] ++;
        if(i + m[i] > r) l = i - m[i], r = i + m[i];
    }
    m.erase(begin(m));
    sz --;
    for(ll i = 0; i < sz; i ++) {
        if((i & 1) == (m[i] & 1)) m[i] ++;
    }
    return m;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n; cin >> n;
    string s; cin >> s;
    vector <ll> m = manacher(s);
    for(ll i = 0; i < (ll) m.size(); i ++) {
        ll len = m[i];
        if(i & 1) {
            ll cur = (i + 1) / 2;
            ll l = cur - len / 2 + 1;
            st[l] ++, st[cur + 1] --;
            ll r = cur + len / 2;
            en[cur + 1] ++, en[r + 1] --;
        }
        else {
            ll cur = (i + 2) / 2;
            ll l = cur - len / 2;
            st[l] ++, st[cur + 1] --;
            ll r = cur + len / 2;
            en[cur] ++, en[r + 1] --;
        }
    }
    for(ll i = 1; i <= n; i ++) {
        st[i] += st[i - 1];
        en[i] += en[i - 1];
    }
    ll ans = 0;
    for(ll i = 1; i < n; i ++) ans += 1LL * en[i] * st[i + 1];
    cout << ans << "\n";

    return 0;
}
