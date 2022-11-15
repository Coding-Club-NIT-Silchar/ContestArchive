#include<bits/stdc++.h>
using namespace std;

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n, 1e9));
        dp[0][0] = 0;
        dp[1][0] = 0;
        for(auto &i : a) {
            for(auto &j : i) {
                cin >> j;
            }
        }
        set<pair<int,pair<int, int>>> q;
        q.insert({0, {0, 0}});
        q.insert({0, {1, 0}});
        set<int> unvisited_vertices[2];
        for(int i = 1 ; i < n; ++i) {
            for(int j = 0 ; j < 2 ; ++j) {
                unvisited_vertices[j].insert(i);
            }
        }
        while(!q.empty()) {
            auto [i, j] = q.begin() -> second;
            q.erase(q.begin());
            while(!unvisited_vertices[i ^ 1].empty()) {
                auto y = unvisited_vertices[i ^ 1].upper_bound(j);
                if(y == unvisited_vertices[i ^ 1].end() || *y > j + a[i][j]) break;
                if(a[i ^ 1][*y]) {
                    if(dp[i ^ 1][*y] > dp[i][j]) {
                        dp[i ^ 1][*y] = dp[i][j] ;
                        q.insert({dp[i ^ 1][*y], {i ^ 1, *y}});
                    }
                }
                else {
                    if(dp[i][*y] > dp[i][j]) {
                        dp[i][*y] = 1 + dp[i][j] ;
                        q.insert({dp[i][*y], {i, *y}});
                    }
                }
                unvisited_vertices[i ^ 1].erase(y);
            }
        }

        cout << (min(dp[0][n - 1], dp[1][n - 1]) <= m ? "YES" : "NO") << '\n' ;
    }

    return 0;
}
