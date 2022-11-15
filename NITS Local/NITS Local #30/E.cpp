#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main () {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
 
    map<string,string> m ;
    string head ; 
 
    string prv ; cin >> prv ;
    head = prv; 
 
    for(int i = 1; i < n; ++i) {
        string s; cin >> s ;
        m[prv] = s; 
        prv = s ; 
    }
    m[prv] = "-"; 
 
    int q; cin >> q ;
 
    while(q--) {
        
        string t; cin >> t;
    
        if(t[0] == 's') {
            head = m[head] ; 
        }
        else if(t[0] == 'i') {
            string a, b; cin >> a >> b;
            if(m[b] != "") {
                m[a] = m[b]; 
                m[b] = a; 
            }
 
        }
        else {
            string s; cin >> s;
            m[s] = head; 
            head = s; 
        }
    }
    
    while(m.count(head)) {
        cout << head << " " ; 
        head = m[head]; 
    }

    return 0;
}
