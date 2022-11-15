#include<bits/stdc++.h>
using namespace std;

#define int long long

int orientation(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int v = a.first *(b.second - c.second) + b.first * (c.second - a.second) + c.first *(a.second - b.second);
    if (v < 0) return - 1; // clockwise
    if (v > 0) return 1; // counter-clockwise
    return 0;
}

int dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void solve() {

    int n, l;
    cin >> n >> l;
    assert(l <= 2e9);
    vector<pair<int, int>> v(n);
   for(auto &[x, y] : v){
        cin >> x >> y;
        assert(1 <= x && x <= 1e9);
        assert(1 <= y && y <= 1e9);
    }
    sort(v.begin(), v.end());
    vector<int> st;
    st.push_back(0);
    st.push_back(1);
    for(int i = 2; i < n; ++i) {
        int siz = st.size();
        while((int)st.size() > 1 && dist(v[i], v[st[siz - 2]]) <= l * l && orientation(v[st[siz - 2]], v[st[siz - 1]], v[i]) != -1) {
            st.pop_back();
            -- siz;
        }
        assert(dist(v[i], v[st[siz - 1]]) <= l * l);
        st.push_back(i);
    }
    cout << (int)st.size() - 1 << '\n';
}

signed main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T --) {
        solve();
    }

    return 0;
}
