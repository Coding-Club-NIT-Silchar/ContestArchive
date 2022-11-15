//Time complexity - O(n) 

#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n; 
    cin >> n ; 
    vector<int> v(n) ; 
    for(auto &i : v) 
        cin >> i ; 
    cout << 1 + accumulate(v.begin(), v.end(), 0) ; 
}
