#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll P = 27;
const ll MOD = 1e9 + 7;
const int MAX = 4e5 + 10;
ll pw[MAX], dp[MAX], pre[MAX];
struct _hash {
    #define ull unsigned long long
    static ull splitmix64(ull x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(string x) const {
        static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        ull h = hash<string>()(x);
        return splitmix64(h + FIXED_RANDOM);
    }
    template <typename T>
    size_t operator()(T x) const {
        static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template <typename T1,typename T2>
    size_t operator()(pair<T1, T2> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64( 1ll*_hash()(x.first)*37 + _hash()(x.second) + FIXED_RANDOM);
    }
 
    template <typename T>
    size_t operator()(vector<T> v) const {
        uint64_t h = 0;
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        for(auto x:v){
            h<<=32;
            h^= _hash()(x);
            h= _hash()(h);
        }
        return splitmix64(h + FIXED_RANDOM);
    }
    template <typename T>
    size_t operator()(set<T> v) const {
        uint64_t h = 0;
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        for(auto x:v){
            h<<=32;
            h^= _hash()(x);
            h= _hash()(h);
        }
        return splitmix64(h + FIXED_RANDOM);
    }
};
void add(ll &a, ll b) {
	a = (a + b) % MOD;
}
void sub(ll &a, ll b) {
	a = (a - b) % MOD;
	if(a < 0) a += MOD;
}
ll get(int l, int r) {
	ll ret = pre[r];
	if(l > 0) sub(ret, pre[l - 1]);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	pw[0] = 1;
	for(int i = 1; i < MAX; i ++) pw[i] = P * pw[i - 1];
	string s, t;
	cin >> s >> t;
	unordered_set <ll, _hash> hashes;
	int n = s.size(), m = t.size();
	for(int i = 0; i < m; i ++) {
		ll cur = 0;
		for(int j = i; j < m; j ++) {
			cur += (t[j] - 'a' + 1) * pw[j - i];
			hashes.insert(cur);
		}
	}
	dp[0] = 1, pre[0] = 1;
	s = "X" + s;
	for(int i = 1; i <= n; i ++) {
		int j = i, len = 0;
		ll cur = 0;
		while(j > 0) {
			cur = cur * pw[1] + (s[j] - 'a' + 1);
			if(hashes.find(cur) == hashes.end()) break;
			j --, len ++;
		} 
		if(len == 0) return cout << 0, 0;
		add(dp[i], get(i - len, i - 1));
		pre[i] = pre[i - 1];
		add(pre[i], dp[i]);
	}
	cout << dp[n];
	
	return 0;
}
