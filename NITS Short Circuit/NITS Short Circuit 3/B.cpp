#include<bits/stdc++.h>
using namespace std;

int main() {

    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, r1, r2 ;
        cin >> n >> r1 >> r2 ;
        bool first;
        if(r1 == 1 || r2 == n) first = true ;
        else if((n + r1 - r2 - 3) & 1) first = true ;
        else first = false ;
        cout << (first ? "First" : "Second") << '\n' ;
    }

    return 0;
}
