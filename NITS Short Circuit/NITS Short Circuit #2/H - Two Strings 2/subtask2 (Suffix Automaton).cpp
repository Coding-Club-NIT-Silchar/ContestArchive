#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 4e5 + 10;
const ll MOD = 1e9 + 7;
ll dp[MAX], pre[MAX];
struct SuffixAutomaton {
	struct state {
		int len, link;
		map <char, int> transitions;
	};
	int n, last, sz; vector <state> states;
	SuffixAutomaton(int _n) {
		n = _n, sz = 1, last = 0;
		states.resize(2 * n); states[0].len = 0, states[0].link = -1;
	}
	void extend(char c) {
		int cur = sz ++;
		states[cur].len = states[last].len + 1;
		int p;
		for(p = last; p != -1 && !states[p].transitions.count(c); p = states[p].link){
			states[p].transitions[c] = cur;
		}
		if(p == -1) states[cur].link = 0;
		else {
			int q = states[p].transitions[c];
			if(states[p].len + 1 == states[q].len) states[cur].link = q;
			else {
				int clone = sz ++;
				states[clone].len = states[p].len + 1;
				states[clone].transitions = states[q].transitions;
				states[clone].link = states[q].link;
				for(; p != -1 && states[p].transitions[c] == q; p = states[p].link) {
					states[p].transitions[c] = clone;
				}
				states[q].link = states[cur].link = clone;
			}
		}
		last = cur;
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
	
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = "X" + s;
	SuffixAutomaton SA(m);
	for(char c : t) SA.extend(c);
	dp[0] = 1, pre[0] = 1;
	int p = 0, len = 0;
	for(int i = 1; i <= n; i ++) {
		while(p && !SA.states[p].transitions.count(s[i])) {
			p = SA.states[p].link;
			len = SA.states[p].len;
		}
		if(!SA.states[p].transitions.count(s[i])) return cout << 0, 0;
		p = SA.states[p].transitions[s[i]];
		len ++;
		add(dp[i], get(i - len, i - 1));
		pre[i] = pre[i - 1];
		add(pre[i], dp[i]);
	}
	cout << dp[n];
	
	return 0;
}
