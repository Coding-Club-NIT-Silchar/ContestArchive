#include<bits/stdc++.h>
using namespace std;

struct Trie{
    struct node {
        int cnt;
        node* child[26] ;
        node() {
            cnt = 0;
            for(int i = 0 ; i < 26 ; ++i) child[i] = NULL ; 
        } 
    };

    node* root ;
    Trie() {
        root = new node(); 
    }
 
    void add(string &s) {
        node* ex = root ;
        for(auto i : s) {
            if(root->child[i-'a'] == NULL) {
                root->child[i-'a'] = new node() ;
            }
            root = root->child[i-'a'] ;
            root -> cnt ++;
        }
        root = ex; 
    }

    pair<long long, int> dfs(string &s) {
        int len = 0, mx_len = 0;
        long long prob = 0 ;
        node* ex = root ;
        for(auto i : s) {
            if(root->child[i-'a'] == NULL) {
                break ;
            }
            root = root->child[i-'a'] ;
            ++len ;
            if(len * 1ll * root -> cnt > prob) {
                prob = len * 1ll * root -> cnt ;
                mx_len = len ;
            }
        }
        root = ex; 
        return {prob, mx_len};
    }

    void dealloc(node *temp) {
        if(temp == NULL) return ;
        for(int i = 0 ; i < 26 ; ++i) {
            dealloc(temp -> child[i]) ;
        }
        delete temp ;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n ;
        string s; cin >> s ;      
        long long prob = 0 ;
        Trie t;
        string result ;
        for(int i = 0 ; i < n ; ++i) {
            string ss;
            for(int j = i ; j < n && (s[j] >= 'a' && s[j] <= 'z'); ++j) {
                ss += s[j];
            }
            t.add(ss) ;
        }
        for(int i = 0 ; i < n ; ++i) {
            string ss;
            for(int j = i ; j < n && (s[j] >= 'a' && s[j] <= 'z'); ++j) {
                ss += s[j];
            }
            auto new_prob = t.dfs(ss);
            if(new_prob.first > prob) {
                prob = new_prob.first ;
                result = ss.substr(0, new_prob.second) ;
            }
        }
        cout << result << '\n' ;
        t.dealloc(t.root);
    }
} 
