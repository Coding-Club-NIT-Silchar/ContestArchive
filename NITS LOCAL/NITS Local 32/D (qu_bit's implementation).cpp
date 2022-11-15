#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m; cin>>n>>m;
    if(n-1>m || (n==3 && m==2))
    {
        cout<<"NO"<<endl;
        return 0;
    }

    ll a[n][m+1];
    for(int j=1; j<m+1; j++) a[0][j]=j;
    for(int i=1; i<n; i++)
    {
        set<ll> s;
        for(int j=1; j<m+1; j++) s.insert(j);
        a[i][i]=i; 
        s.erase(i);
        if(i==m)
        {
            a[i][i-1]=1;
            for(int j=1; j<m-1; j++) a[i][j]=j+1;
            break;
        }

        ll j=i+1;
        while(!s.empty())
        {
            if(j>m) j=1;
            ll x=*s.begin();
            s.erase(x);
            a[i][j]=x;
            j++;
        }
    }

    cout<<"YES"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<m+1; j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
