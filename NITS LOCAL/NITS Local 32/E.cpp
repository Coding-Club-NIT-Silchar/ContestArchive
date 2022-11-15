//Time complexity - O(n) 

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin>>tc;
    while(tc--)
    {
        int n, w; 
        cin >> n >> w;
        ll a[n];
        for(int i = 0 ; i < n ; i++) cin >> a[i];

        vector<ll> dp(n), mx(n);
        for(int i = 0; i < n ; i++)
        {
            if(i-w < 0) 
            { 
                dp[i] = 0; 
                mx[i] = (i==0) ? -a[i] : max(mx[i-1],-a[i]) ; 
            }
            else
            {
                dp[i] = max(dp[i-1], a[i] + mx[i-w]);
                mx[i] = max(mx[i-1], dp[i-w] - a[i]);
            }
        }

        cout << dp[n-1] << '\n';
    }
}
