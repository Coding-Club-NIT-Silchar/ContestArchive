#include<bits/stdc++.h>
using namespace std;
 
const int N = 1005;

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> v(N);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x] ++;
    }
    int mex = 0;
    while(mex < N && v[mex]) {
        ++ mex;
    }
    cout << mex;
 
    return 0;
}
