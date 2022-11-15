#include<bits/stdc++.h>
using namespace std;

#define sz(a) (int)a.size()
#define rep(i, begin, end) for(int i = begin ; i < end ; ++i)
#define ll long long

void count_sort(vector<pair<ll,int>> &b, int bits) { // (optional)
    //this is just 3 times faster than stl sort for N=10^6
    int mask = (1 << bits) - 1;
    rep(it,0,2) {
        int move = it * bits;
        vector<int> q(1 << bits), w(sz(q) + 1);
        rep(i,0,sz(b))
            q[(b[i].first >> move) & mask]++;
        partial_sum(q.begin(), q.end(), w.begin() + 1);
        vector<pair<ll,int>> res(sz(b));
        rep(i,0,sz(b))
            res[w[(b[i].first >> move) & mask]++] = b[i];
        swap(b, res);
    }
}
struct SuffixArray {
    vector<int> a, s;
    SuffixArray(vector<int> &v) {
        s = v;
        int N = sz(s);
        vector<pair<ll,int>> b(N);
        a.resize(N);
        rep(i,0,N) {
            b[i].first = s[i];
            b[i].second = i;
        }
 
        int q = 8;
        while ((1 << q) < N) q++;
        for (int moc = 0;; moc++) {
            count_sort(b, q); // sort(all(b)) can be used as well
            a[b[0].second] = 0;
            rep(i,1,N)
                a[b[i].second] = a[b[i - 1].second] +
                    (b[i - 1].first != b[i].first);
 
            if ((1 << moc) >= N) break;
            rep(i,0,N) {
                b[i].first = (ll)a[i] << q;
                if (i + (1 << moc) < N)
                    b[i].first += a[i + (1 << moc)];
                b[i].second = i;
            }
        }
        rep(i,0,sz(a)) a[i] = b[i].second;
    }
    vector<int> lcp() {
        // longest common prefixes: res[i] = lcp(a[i], a[i-1])
        int n = sz(a), h = 0;
        vector<int> inv(n), res(n);
        rep(i,0,n) inv[a[i]] = i;
        rep(i,0,n) if (inv[i] > 0) {
            int p0 = a[inv[i] - 1];
            while (i + h < sz(s) && p0 + h < sz(s) && s[i + h] == s[p0 + h]) h++;
            res[inv[i]] = h;
            if(h > 0) h--;
        }
        return res;
    }
};

signed main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n ;
        string s; cin >> s ;
        int cnt = 1;
        vector<int> v;
        for(int i = 0 ; i < n ; ++i) {
            if(s[i] >= 'a' && s[i] <= 'z') v.push_back(0) ;
            else if(i == 0 || (s[i-1] >= 'a' && s[i-1] <= 'z')) v.push_back(cnt ++) ;
        }
        
        v.push_back(cnt++);
        int it = 0 ;
        for(int i = 0 ; i < n ; ++i) {
            if(s[i] >= 'a' && s[i] <= 'z') v[it++] = s[i] - 'a' + cnt ;
            else if(i == 0 || (s[i-1] >= 'a' && s[i-1] <= 'z')) ++it ;
        }
        
        SuffixArray sf(v);
        vector<int> LCP = sf.lcp();

        int N = sz(v) ;
        vector<int> next_smaller(N, N), prev_smaller(N, 0);
        stack<pair<int,int>> st;
        for(int i = 0 ; i < N ; ++i) {
            while(!st.empty() && st.top().first > LCP[i]) {
                next_smaller[st.top().second] = i ;
                st.pop();
            }
            st.push({LCP[i], i});
        }
        while(!st.empty()) st.pop() ;
        for(int i = N-1 ; i >= 0 ; --i) {
            while(!st.empty() && st.top().first > LCP[i]) {
                prev_smaller[st.top().second] = i ;
                st.pop();
            }
            st.push({LCP[i], i});
        }
        
        ll ans = 0, idx = 0, len = 0;
        for(int i = 0 ; i < N ; ++i) {
            int l = prev_smaller[i] ;
            int r = next_smaller[i] ;
            if(LCP[i] * 1ll * (r - l) > ans) {
                ans = LCP[i] * 1ll * (r - l) ;
                idx = sf.a[i] ;
                len = LCP[i] ;
            }
        }
        
        for(int i = 0 ; i < N ; ++i) {
            if(v[i] >= cnt) {
                int j = i;
                while(j < N && v[j] >= cnt) ++j ;
                if(j-i > ans) {
                    ans = j-i ;
                    idx = i ;
                    len = j-i ;
                }
                i = j-1 ;
            }
        }
        for(int i = idx ; i < idx + len ; ++i) cout << char('a' + v[i] - cnt);
        cout << '\n';
    }

    return 0;
}
