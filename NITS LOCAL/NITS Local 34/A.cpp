#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    set <int> s;
    while(n --) {
        int x; cin >> x;
        s.insert(x);
    }
    cout << int(s.size());

    return 0;
}
