#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
int r, c, n; 
int x[2][MAX], y[2][MAX];
vector <pair <int, int>> v[4];
bool boundary(pair <int, int> p) {
    return p.first == 0 || p.first == r || p.second == 0 || p.second == c;
}
void add(pair <int, int> p, int i, int j) {
    if(p.second == 0 && p.first < r) v[0].push_back({i, j});
    else if(p.first == r && p.second < c) v[1].push_back({i, j});
    else if(p.second == c && p.first > 0) v[2].push_back({i, j});
    else if(p.first == 0 && p.second > 0) v[3].push_back({i, j});
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> r >> c >> n;
    for(int i = 0; i < n; i ++) {
        cin >> x[0][i] >> y[0][i] >> x[1][i] >> y[1][i];
        if(boundary({x[0][i], y[0][i]}) && boundary({x[1][i], y[1][i]})) {
            for(int j = 0; j < 2; j ++) add({x[j][i], y[j][i]}, i, j);
        }
    }
    sort(v[0].begin(), v[0].end(), [&] (pair <int, int> a, pair <int, int> b) {
        return x[a.second][a.first] < x[b.second][b.first];
    });
    sort(v[1].begin(), v[1].end(), [&] (pair <int, int> a, pair <int, int> b) {
        return y[a.second][a.first] < y[b.second][b.first];
    });
    sort(v[2].begin(), v[2].end(), [&] (pair <int, int> a, pair <int, int> b) {
        return x[a.second][a.first] > x[b.second][b.first];
    });
    sort(v[3].begin(), v[3].end(), [&] (pair <int, int> a, pair <int, int> b) {
        return y[a.second][a.first] > y[b.second][b.first];
    });
    stack <int> s;
    for(int i = 0; i < 4; i ++) {
        for(auto p : v[i]) {
            int x = p.first;
            if(s.empty()) s.push(x);
            else {
                if(s.top() == x) s.pop();
                else s.push(x);
            }
        }
    }
    cout << (s.empty() ? "YES" : "NO");

    return 0;
}
