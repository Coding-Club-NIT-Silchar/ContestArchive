#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t --) {
        int n, p;
        cin >> n >> p;
        for(int x = 0; x <= n; x ++) {
            int y = 5 * x - p;
            int z = n - x - y;
            if(y >= 0 && y <= n && z >= 0 && z <= n && x + y + z == n && 5 * x - y == p) {
		cout << x << " " << y << " " << z << "\n";
		break;
             }
        }
    }

    return 0;
}
