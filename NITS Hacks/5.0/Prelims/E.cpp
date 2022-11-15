#include<bits/stdc++.h>
using namespace std;

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 1;
    for(int i = 1; i < n; ++i) {
        ans += a[i] != a[i - 1];
    }
    cout << ans;

    return 0;
}
