#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int sv[N], pf[N], ans[N];

int main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; ++i) {
        if(!sv[i]) {
            for(int j = 2 * i; j < N; j += i) {
                sv[j] = 1;
            }
        }
        pf[i] = pf[i - 1] + (sv[i] == 0);
        ans[i] = ans[i - 1] + (pf[i] % 2 == 0);
    }

    int T;
    cin >> T;
    while(T --) {
        int l, r;
        cin >> l >> r;
        cout << ans[r] - ans[l - 1] << '\n';
    }

    return 0;
}
