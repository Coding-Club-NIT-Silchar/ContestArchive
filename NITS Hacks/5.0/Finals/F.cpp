#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   int t; cin>>t;
   while(t--)
   {
       int n; cin>>n;
       string s; cin>>s;
 
       string a;
       a += s[0];
       for(int i = 1; i < n; i++) 
       {
           int x1 = (s[i-1] == 'T') ? 1 : 0;
           int x2 = (s[i] == 'T') ? 1 : 0;
           int x = x1 ^ x2;
           a += (x == 1) ? 'T' : 'F';
       }
       
       int ans = 0;
       for(int i = 0; i < n; i++) {
           if(a[i] == 'F') ans++;
       }
       
       cout<<ans<<endl;
   }
   return 0;
}
