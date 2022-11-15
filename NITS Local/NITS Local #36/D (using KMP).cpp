#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> prefix_function(vector <int> s) {
    int n = s.size();
    int cnt = 0;
    vector <int> pi(n);
    for(int i = 1; i < n; i ++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] < s[j]) {
            cnt ++;
            j = pi[j - 1];
        }
        if(s[i] >= s[j]) j ++;
        pi[i] = j;
    }
    return pi;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector <int> v;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        v.push_back(x);
    }
    v.push_back(INT_MAX);
    for(int i = 0; i < m; i ++) {
        int x; cin >> x;
        v.push_back(x);
    }
    vector <int> pre = prefix_function(v);
    int cnt = 0;
    for(int i = 2 * n; i < n + m + 1; i ++) cnt += pre[i] == n;
    cout << cnt;
}
