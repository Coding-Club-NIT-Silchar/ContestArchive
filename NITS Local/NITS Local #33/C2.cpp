#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve()
{   
   	ll k; cin>>k;
	if(k<0) k*=-1;
	        
	vector<int> bit(40,0);
	int j=0;
	while(k>0)
	{
	    bit[j]=(int)(k%2);
	    j++;
	    k/=2;
	}
	        
	int fl=0;
	for(int i=0; i<40; i++)
	{
	    if(bit[i]==1 && bit[i+1]==1 && fl==0) 
	    {
	        bit[i]=-1;
	        fl=1;
	    }
	    else if(bit[i]==1 && bit[i+1]==1 && fl==1)
	    {
	        bit[i]=0; 
	    }
	    else if(bit[i]==1 && bit[i+1]==0 && fl==1)
	    {
	        bit[i]=0;
	        bit[i+1]=1;
	        fl=0;
	    }
	}
	        
	int ans=0;
	for(int i=0; i<40; i++) 
	{
	    if(bit[i]!=0) ans++;
	}
	cout<<ans<<endl;
    
}
 
int main()
{
    int tc; cin>>tc; while(tc--)
    solve();
}
