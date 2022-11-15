/*I wanna be the very best, like no one ever was...*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 5;
void add(ll &a, ll b) {
	b %= MOD;
	a = (a + b) % MOD;
}
void MatMul(ll M1[MAX][MAX], ll M2[MAX][MAX]) {
	ll temp[MAX][MAX] = {0};
	for(int i = 0; i < MAX; i ++) {
		for(int j = 0; j < MAX; j ++) {
			for(int k = 0; k < MAX; k ++) {
				add(temp[i][j], M1[i][k] * M2[k][j]);
			}
		}
	}
	for(int i = 0; i < MAX; i ++) for(int j = 0; j < MAX; j ++) M1[i][j] = temp[i][j];
}
void MatExp(ll mat[MAX][MAX], ll p) {
	ll I[MAX][MAX] = {0};
	for(int i = 0; i < MAX; i ++) I[i][i] = 1;
	while(p > 0) {
		if(p & 1) MatMul(I, mat);
		MatMul(mat, mat);
		p >>= 1;
	}
	for(int i = 0; i < MAX; i ++) for(int j = 0; j < MAX; j ++) mat[i][j] = I[i][j];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t --) {
		ll n; cin >> n;
		ll mat[MAX][MAX] = {{1, 1, 1, 1, 1},
				    {1, 0, 0, 1, 0},
				    {1, 0, 0, 0, 0},
			 	    {1, 1, 0, 0, 0},
				    {1, 0, 0, 0, 0}};
		MatExp(mat, n);
		ll ans = 0;
		for(int i = 0; i < MAX; i ++) add(ans, mat[0][i]);
		cout << ans - 1 << "\n";
	}
	
	return 0;
}
