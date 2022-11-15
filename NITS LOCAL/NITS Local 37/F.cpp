#include<bits/stdc++.h>
using namespace std;
 
struct node{
    int length, next[26], suffix_edge;
    node() {
        length = suffix_edge = 0;
        for(int i = 0; i < 26; ++i) next[i] = 0;
    }
    void reset() {
        length = suffix_edge = 0;
        for(int i = 0; i < 26; ++i) next[i] = 0;
    }
};
 
const int N = 5e5 + 10;
node root1, root2;
node tree[N];
int cur_node, ptr, ans, pf[N][26], k;
string s;
 
void get_max_suffix(int &temp, int idx) {
    while(true) {
        int cur_length = tree[temp].length;
        if(idx - cur_length > 0 && s[idx] == s[idx - cur_length - 1]) {
            break;
        }
        temp = tree[temp].suffix_edge;
    }
}
 
void insert(int idx) {
    int temp = cur_node;
    get_max_suffix(temp, idx);
    if(tree[temp].next[s[idx] - 'a']) {
        cur_node = tree[temp].next[s[idx] - 'a'];
        return;
    }
    int distinct = 0, cur_length = tree[temp].length;
    for(int j = 0; j < 26; ++j) {
        distinct += pf[idx][j] != pf[idx - cur_length - 2][j];
    }
    ans += distinct <= k;
    ptr ++;
    tree[temp].next[s[idx] - 'a'] = ptr;
    tree[ptr].length = tree[temp].length + 2;
 
    cur_node = ptr;
    temp = tree[temp].suffix_edge;
    if(tree[cur_node].length == 1) {
        tree[cur_node].suffix_edge = 2;
        return;
    }
    get_max_suffix(temp, idx);
    tree[cur_node].suffix_edge  = tree[temp].next[s[idx] - 'a'];
}
 
void reset(int n) {
    for(int i = 0; i <= n + 5; ++i) {
        tree[i].reset();
        for(int j = 0; j < 26; ++j) {
            pf[i][j] = 0;
        }
    }
    root1.length = -1;
    root1.suffix_edge = 1;
    root2.length = 0;
    root2.suffix_edge = 1;
 
    tree[1] = root1;
    tree[2] = root2;
 
    ptr = 2;
    cur_node = 1;
}
 
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n >> k;
        cin >> s;
        reset(n);
        s = "#" + s;
        ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 26; ++j) {
                pf[i][j] = pf[i - 1][j];
            }
            pf[i][s[i] - 'a'] ++;
            insert(i);
        }
        cout << ans << '\n';
    }
 
    return 0;
}
