#include<bits/stdc++.h>
using namespace std ;

const int INF = 1e9;

struct node {
    int max_prefix_sum, max_suffix_sum, max_subarray_sum, total_sum;
    node() : max_prefix_sum(0), max_suffix_sum(0), max_subarray_sum(0), total_sum(0) {}
    void init(char ch) {
        int x;
        if(ch == 'I') x = 1;
        else x = -1;
        max_prefix_sum = max_suffix_sum = max_subarray_sum = total_sum = x;
    }
};

const int N = 1e5 + 5;
node tree[4 * N];
string s;
 
node merge(node left_child, node right_child) {
    node parent;
    parent.max_prefix_sum = max(left_child.max_prefix_sum, left_child.total_sum + right_child.max_prefix_sum);
    parent.max_suffix_sum = max(right_child.max_suffix_sum, right_child.total_sum + left_child.max_suffix_sum);
    parent.total_sum = left_child.total_sum + right_child.total_sum ;
    parent.max_subarray_sum = max({left_child.max_subarray_sum, 
                                right_child.max_subarray_sum, 
                                left_child.max_suffix_sum + right_child.max_prefix_sum});

    return parent;
}

void build(int tree_idx, int start, int end) {
    if(start == end) {
        tree[tree_idx].init(s[start - 1]) ;
        return ;
    }
    int mid = start + end >> 1; 
    build(tree_idx << 1, start, mid);
    build(tree_idx << 1 | 1, mid + 1, end);
    tree[tree_idx] = merge(tree[tree_idx << 1], tree[tree_idx << 1 | 1]);
}

node query(int tree_idx, int start, int end, int l, int r) {
    if(start > r || end < l || start > end) return node();
    if(start >= l && end <= r) return tree[tree_idx];
    int mid = start + end >> 1; 
    return merge(query(tree_idx << 1, start, mid, l, r), 
                query(tree_idx << 1 | 1, mid + 1, end, l, r));
}

int main() {
    
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        cin >> s;
        build(1, 1, n);
        int initial_Gs = count(s.begin(), s.end(), 'G');
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << initial_Gs + max(0, query(1, 1, n, l, r).max_subarray_sum) << '\n';
        }
    }

    return 0;
}
