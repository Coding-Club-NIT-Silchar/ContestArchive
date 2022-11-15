#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
int p[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
    }
    int ans = 0;
    for(int i = 2; i < n; i ++) {
        if(p[i] > p[i - 1] && p[i] > p[i + 1]) ans ++;
    }
    cout << ans;

    return 0;
}

