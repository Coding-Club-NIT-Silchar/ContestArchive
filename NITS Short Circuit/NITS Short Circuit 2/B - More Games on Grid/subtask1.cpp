#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
const int MAX = 1e5 + 10;
int a[2][MAX]; bool vis[2][MAX];
int n, m;
bool valid(int x, int y) {
	return x >= 0 && y >= 0 && x < 2 && y < n && a[x][y] == 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		cin >> n >> m;
		for(int i = 0; i < 2; i ++) {
			for(int j = 0; j < n; j ++) {
				a[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		for(int i = 0; i < m; i ++) {
			int r, c;
			cin >> r >> c;
			a[r - 1][c - 1] = 1;
		}
		queue <pair <int, int>> q;
		q.push({0, 0}); vis[0][0] = true;
		while(!q.empty()) {
			auto p = q.front(); q.pop();
			int cx = p.first, cy = p.second;
			for(int i = 0; i < 4; i ++) {
				int nx = cx + dx[i], ny = cy + dy[i];
				if(valid(nx, ny) && !vis[nx][ny]) {
					vis[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
		cout << (vis[1][n - 1] ? 1 : 0) << "\n";
	}	
	
	return 0;
}
