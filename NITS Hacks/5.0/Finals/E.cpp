#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n; 
string s; 
vector<pair<int, int>> op;

void find(int L, int R)
{
    if(L > R) return;

    int ca = 0, cb = 0;
    vector<pair<int,int>> parts;
    int pv = L;
    for(int i = L; i <= R; i++)
    {
        if(s[i] == 'a') ca++;
        else cb++;

        if(ca == cb)
        {
            parts.pb({pv, i});
            pv = i+1;
        }
    }

    for(auto &[l,r]: parts)
    {
        // doing op 1 on 1st x
        op.pb({1,1}); 

        if(s[l] == 'a' && s[r] == 'b') 
        {
            // doing op 2 on 1st x
            op.pb({2, 1});
        }
        else if(s[l] == 'b' && s[r] == 'a') 
        {
            // doing op 3 on 1st x
            op.pb({3, 1});
        }

        l++; r--;
        find(l,r);

        // doing op 4 on 1st x
        op.pb({4,1});
    }
}   

void solve()
{
    cin >> n;
    cin >> s;

    int ca = 0, cb = 0;
    for(int i = 0; i < n; i++)
    {   
        if(s[i] == 'a') ca++;
        else cb++;
    }

    if(ca != cb) 
    {
        cout << "NO" << endl;
        return;
    }

    op.clear();
    find(0, n-1);
    op.pb({4,1});

    cout << "YES" << endl;
    cout << op.size() << endl;
    for(auto &[i,x]: op) 
      cout << i << " " << x << endl;
    
}

int main()
{
    int tc; cin >> tc;
    while(tc --) solve();
    return 0;
}
