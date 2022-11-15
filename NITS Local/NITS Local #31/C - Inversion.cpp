#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
int p[MAX], pos[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
    }
    int invert = 0;
    while(m --) {
        int x; cin >> x;
        if(x == 1) invert ^= 1;
        else {
            if(invert) {
                for(int i = 1; i <= n; i ++) pos[p[i]] = i;
                for(int i = 1; i <= n; i ++) p[i] = pos[i];
            }
            invert = 0;
            int u, v;
            cin >> u >> v;
            swap(p[u], p[v]);
        }
    }
    if(invert) {
        for(int i = 1; i <= n; i ++) pos[p[i]] = i;
        for(int i = 1; i <= n; i ++) p[i] = pos[i];
    }
    for(int i = 1; i <= n; i ++) cout << p[i] << " ";

    return 0;
}

