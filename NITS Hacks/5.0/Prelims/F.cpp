#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

struct node{
    int length;
    int lval;
    int rval;
    int llen;
    int rlen;
    int ans;
    
    node() {
        length = lval = rval = llen = rlen = ans = 0;
    }

    void init(int x) {
        length = llen = rlen = ans = 1;
        lval = rval = x;
    }
};

const int N = 2e5 + 1;
node tree[4 * N + 5];
int a[N];

node merge(node left, node right) {
    node par;
    
    par.length = left.length + right.length;
    par.lval = left.lval;
    par.rval = right.rval;
    par.llen = left.llen;
    par.rlen = right.rlen;

    if(left.rval == right.lval) {
        par.ans = left.rlen + right.llen;
        if(left.length == left.llen) {
            par.llen = left.length + right.llen;
        }
        if(right.length == right.rlen) {
            par.rlen = right.length + left.rlen;
        }
    }
    par.ans = max({par.ans, left.ans, right.ans});
    return par;
}

void build(int tree_idx, int start, int end) {
    if(start == end) {
        tree[tree_idx].init(a[start]);
        return;
    }
    int mid = start + end >> 1;
    build(tree_idx << 1, start, mid);
    build(tree_idx << 1 | 1, mid + 1, end);
    tree[tree_idx] = merge(tree[tree_idx << 1], tree[tree_idx << 1 | 1]);
}

void update(int tree_idx, int start, int end, int idx, int val) {
    if(start == end) {
        a[start] = val;
        tree[tree_idx].init(a[start]);
        return;
    }
    int mid = start + end >> 1;
    if(start <= idx && idx <= mid) update(tree_idx << 1, start, mid, idx, val);
    else update(tree_idx << 1 | 1, mid + 1, end, idx, val);
    tree[tree_idx] = merge(tree[tree_idx << 1], tree[tree_idx << 1 | 1]);
}

node query(int tree_idx, int start, int end, int l, int r) {
    if(start > r || end < l || start > end) return node();
    if(start >= l && end <= r) return tree[tree_idx];
    int mid = start + end >> 1; 
    return merge(query(tree_idx << 1, start, mid, l, r), query(tree_idx << 1 | 1, mid + 1, end, l, r));
}

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    assert(n >= 1 && n <= 2e5);
    assert(q >= 1 && q <= 2e5);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        assert(a[i] >= 1 && a[i] <= 1e9);
        a[i] -= i;
    }
    build(1, 1, n);
    while(q --) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            assert(x >= 1 && x <= n);
            assert(y >= 1 && y <= 1e9);
            y -= x;
            update(1, 1, n, x, y);
        }
        else {
            assert(x >= 1 && x <= n);
            assert(y >= 1 && y <= n);
            assert(x <= y);
            node ans = query(1, 1, n, x, y);
            cout << ans.ans << '\n';
        }
    }

    return 0;
}
