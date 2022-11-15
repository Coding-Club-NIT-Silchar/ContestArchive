// Time complexity - O(N + klogk) 

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll N,M,k;
    cin>>N>>M>>k;
 
    vector<pair<ll,ll>> v;
    for(int i=0; i<k; i++) 
    {
        ll x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
 
    vector<vector<ll>> a(N);
    for(int i=0; i<k; i++) a[v[i].first].push_back(v[i].second);
 
    ll INF = 1e18;
    vector<ll> d(k+1, INF);
    d[0] = -INF;
    for(ll i=0; i < N; i++)
    {
        map<ll,ll> m;
        for(auto x:a[i])
        {
            int j = upper_bound(d.begin(), d.end(), x) - d.begin();
            if (d[j-1] < x && x < d[j])
            {
                if(m.find(j)==m.end()) m[j]=x;
                else if(x < m[j]) m[j]=x;
            }
        }
 
        for(auto x:m) d[x.first]=x.second;
    }
    
    ll lis = 0;
    for (int i = 0; i <= k; i++) 
        if (d[i] < INF) lis = i;
 
    ll ans=2*(N+M)-3*lis;
    cout<<ans;
}
