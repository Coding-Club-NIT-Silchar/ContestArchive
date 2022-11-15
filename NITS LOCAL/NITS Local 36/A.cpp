#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector <int> a(n);
    for(int &x : a) cin >> x;
    for(int i = 0; i < n - 1; i ++) cout << a[i] - 1 << " ";
    cout << a[n - 1] + n - 1;
 
    return 0;
}
