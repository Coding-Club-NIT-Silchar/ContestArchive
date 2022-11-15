#include<bits/stdc++.h>
using namespace std ;

int main() {
    
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        string s; 
        cin >> s;
        int initial_Gs = count(s.begin(), s.end(), 'G');
        while(q--) {
            int l, r;
            cin >> l >> r;
            --l ;
            int max_sum = 0, cur_sum = 0 ;
            for(int i = l ; i < r; ++i) {
                if(s[i] == 'I') ++ cur_sum ;
                else -- cur_sum ;
                max_sum = max(max_sum, cur_sum) ;
                cur_sum = max(cur_sum, 0) ;
            } 
            cout << initial_Gs + max_sum << '\n' ;
        }
    }

    return 0;
}
