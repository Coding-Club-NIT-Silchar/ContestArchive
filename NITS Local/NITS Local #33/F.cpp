#include<bits/stdc++.h>
using namespace std ;

#define int long long 

struct Node {
    int sum, A, D;
    Node() {
        sum = A = D = 0 ; 
    }
    void reset() {
        A = D = 0;
    }
};

const int N = 2e5 + 5 ;
Node tree[2][4*N];
int n, q; 

void prop(int node, int start, int end, int T) {
    int mid = (start + end) / 2; 

    if(tree[T][node].A) {
        int s = (end-start+1) ;
        tree[T][node].sum += s * (2 * tree[T][node].A + (s-1) * tree[T][node].D)/2 ;
        
        if(start != end) {
            tree[T][2*node].A += tree[T][node].A;
            tree[T][2*node+1].A += tree[T][node].A + (mid+1-start) * tree[T][node].D ; 
            tree[T][2*node].D += tree[T][node].D;
            tree[T][2*node+1].D += tree[T][node].D ; 
        }

        tree[T][node].reset() ;
    }
}

void update(int l, int r, int a, int T, int node=1, int start = 1, int end = n) {
    prop(node,start,end, T) ;
    if(start > end or start > r or end < l) return ;
    int mid = (start + end) / 2; 
    if(start >= l and end <= r ) {
        int s = (end - start + 1) ; 
        tree[T][node].sum += s * (2 * (start-l+a) + (s-1)) / 2 ;
        if(start != end ) {
            tree[T][2*node].A += (start-l+a);
            tree[T][2*node].D ++ ; 
            tree[T][2*node+1].A += (start-l+a) + (mid+1-start); 
            tree[T][2*node+1].D ++ ; 
        }
        return ; 
    }

    update(l,r,a,T,2*node,start,mid);
    update(l,r,a,T,2*node+1,mid+1,end) ;

    tree[T][node].sum = tree[T][2*node].sum + tree[T][2*node+1].sum ;
}

int query(int l, int r, int T, int node=1, int start=1, int end=n) {
    prop(node,start,end, T) ;
    if(start > end or start > r or end < l) return 0 ;
    if(start >= l and end <= r ) return tree[T][node].sum ;
    int mid = (start + end)/2 ;
    return query(l, r, T, 2*node, start, mid) + query(l, r, T, 2*node+1, mid+1, end); 
}

signed main() {
 
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;

    cin >> n >> q; 
    
    while(q--) {
        int t; cin >> t ;
        if(t == 1) {
            int x, y, k ; cin >> x >> y >> k ;
            update((x+1)/2, (x+1)/2+y-1, 1, x&1) ;
             if(k&1) {
                update((x+2*y+k)/2, (n+1)/2, y+1, x&1) ;
            }   
            else {
                update((x+2*y+k)/2, (n+1)/2, y+1, !(x&1)) ;
            }
        }
        else {
            int l, r; cin >> l >> r ;
            cout << query((l+1)/2 + !(l&1), (r+1)/2, 1) + query((l+1)/2, r/2, 0) << '\n' ; 
        }
    }

    return 0 ;

}
