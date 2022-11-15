//Time complexity - O(n) 

#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n; 
    cin >> n ; 
    string s; 
    cin >> s; 
    cout << (count(s.begin(), s.end(), '0')&1 ? "NO" : "YES") ; 
}
