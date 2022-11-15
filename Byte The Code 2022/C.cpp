#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int N = 1e5 + 1;
int a[N] ;
 
int main() {
 
    ios :: sync_with_stdio(0);
    cin.tie(0);
 
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i) {
        int l, r; cin >> l >> r;
        a[l] ++ ;
        a[r + 1] -- ;
    }
    for(int i = 1 ; i < N ; ++i) {
        a[i] += a[i - 1];
    }
    auto check = [&](int mid) {
        ll cnt = 0 ;
        for(int i = 1 ; i < N ; ++i) {
            cnt += max(0, a[i] - mid);
        }
        return cnt <= k;
    };
    int l = 0, r = n;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1;
 
    return 0;
}
