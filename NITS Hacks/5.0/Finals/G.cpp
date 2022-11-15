#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#include<bits/stdc++.h>
using namespace std;

#define int long long 
 
struct node{
    int ans, l_odd, r_odd, l_even, r_even, sum;
    
    node() {
        ans = l_odd = r_odd = l_even = r_even = sum = -1;
    }
 
    void init(int x) {
        x &= 1;
        if(x) {
            l_odd = r_odd = sum = 1;
            ans = l_even = r_even = 0;
        }
        else {
            l_odd = r_odd = sum = 0;
            ans = l_even = r_even = 1;
        }
    }
};
 
const int N = 2e5 + 1;
node tree[4 * N + 5];
int a[N];
 
node merge(node left, node right) {

    if(left.sum == -1) return right;
    if(right.sum == -1) return left;

    node par;
    
    par.ans = left.ans + right.ans + left.r_odd * right.l_odd + left.r_even * right.l_even;
    par.sum = left.sum + right.sum;
    par.l_odd = left.l_odd + (left.sum & 1 ? right.l_even : right.l_odd);
    par.l_even = left.l_even + (left.sum & 1 ? right.l_odd : right.l_even);
    par.r_odd = right.r_odd + (right.sum & 1 ? left.r_even : left.r_odd);
    par.r_even = right.r_even + (right.sum & 1 ? left.r_odd : left.r_even);

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
 
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    while(q --) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            update(1, 1, n, x, y);
        }
        else {
            node ans = query(1, 1, n, x, y);
            cout << ans.ans << '\n';
        }
    }
 
    return 0;
}
