#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
template <class T> struct SegTree {
    const T ID = 0;
    int n; vector <T> seg;
    T comb(T a, T b) { return max(a, b); }
    SegTree(int _n) { n = _n; seg.assign(2 * n, ID); }
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }
    void update(int idx, T val) {
        seg[idx += n] = val;
        for(idx /= 2; idx; idx /= 2) pull(idx);
    }
    T query(int l, int r) {
        T lnode = ID, rnode = ID;
        for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if(l & 1) lnode = comb(lnode, seg[l ++]);
            if(r & 1) rnode = comb(seg[-- r], rnode);
        }
        return comb(lnode, rnode);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    SegTree <int> seg(n + 10);
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        int cur = seg.query(x, x);
        seg.update(x, max(cur, seg.query(1, x - 1) + 1));
    }
    cout << seg.query(1, n);

    return 0;
}
