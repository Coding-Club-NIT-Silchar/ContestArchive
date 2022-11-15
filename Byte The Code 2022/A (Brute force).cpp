#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n, r;
    cin >> n >> r;
    for(int i = 1 ; i <= r ; ++i) {
        if((i * n) % r == 0) {
            int p_r = i, q_r = i * n / r;
            int p_b = q_r - p_r, q_b = q_r;
            cout << p_r << " " << q_r << '\n' ;
            cout << p_b << " " << q_b << '\n' ;
            return 0;
        }
    }

    return 0;
}
