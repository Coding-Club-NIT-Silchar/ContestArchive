// Time complexity - O(KlogK + KlogM)

#include<bits/stdc++.h>
using namespace std ; 
 
template <typename T> 
struct BIT {
    int n; 
    vector<T> bit;
    
    BIT(int x) {
        n = x + 1; 
        bit.resize(n+5) ;
    }
 
    void update(int x, T val) {
        for(; x <= n; x += x&-x)
            bit[x] = max(bit[x], val);
    }
 
    T _query(int x) {
        T mx = 0;
        for(; x > 0; x -= x&-x)
            mx = max(mx, bit[x]);
        return mx;
    }
 
    T query(int l,int r) {
        return _query(r) - _query(l-1) ;
    }
};
 
signed main() {
 
    ios::sync_with_stdio(0) ; 
    cin.tie(0) ; 
 
    int n, m, k; cin >> n >> m >> k ;
    vector<pair<int,int>> v(k) ; 
    
    for(auto &[x,y] : v) {
        cin >> x >> y ; 
        ++x ;
        ++y ; 
    }
        
    sort(v.begin(), v.end()) ; 
    
    BIT<int> bit(m) ;  
 
    for(int i = 0 ; i < k ; ++i) {
        vector<pair<int,int>> temp; 
        int j ; 
        for(j = i ; j < k ; ++j) 
            if(v[i].first != v[j].first) // different x-coordinates
                break ; 
            else
                temp.push_back({v[j].second, 0}) ; 
 
        for(auto &[x,y] : temp) {
            y = 1 + bit.query(0, x-1) ; 
        }
        for(auto [x,y] : temp) { 
            bit.update(x, y) ; 
        }
        i = j-1 ; 
    }
 
    int mx = bit.query(0, m) ; 
    cout << 2*(n+m) - 3 * mx ; 
 
    return 0 ; 
 
}
