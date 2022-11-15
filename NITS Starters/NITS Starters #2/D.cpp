#include<bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin >> n ;  
    int a[n][n] ; 

    for(int i = 0 ; i < n ; ++i) {
        string s; 
        cin >> s; 
        for(int j = 0 ; j < n ; ++j) 
            a[i][j] = s[j] - '0' ; // converting the string to an array 
    }
        
    bool flag = 0 ; 

    for(int i = 1 ; i < n-1 ; ++i) {
        for(int j = 1 ; j < n-1 ; ++j) {
            int sum = a[i][j] + a[i-1][j-1] + a[i-1][j+1] + a[i+1][j-1] + a[i+1][j+1] ; 
            if(sum == 5) {
                flag = true ; 
            }
        }
    }

    cout << (flag ? "YES" : "NO") ; 

    return 0 ; 
}
