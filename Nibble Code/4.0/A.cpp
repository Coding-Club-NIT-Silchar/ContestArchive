#include<bits/stdc++.h>
using namespace std;

int main () {

    int n; cin >> n ;     
    string s; cin >> s; 

    vector<char> v = {'a', 'e', 'i', 'o', 'u'} ; 
    bool flag = 0 ; 
    for(int i = 0 ; i < 5 ; ++i) {
	if(s[0] == v[i]) 
	   flag = true ; 
	if(s[n-1] == v[i]) 
	   flag = true ; 
    }

    cout << (flag ? "YES" : "NO") ; 

    return 0 ; 
}
