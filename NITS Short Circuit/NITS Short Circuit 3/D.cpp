#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m; 
    cin >> n >> m;
    int illuminated[n + 1][m + 1];
    memset(illuminated, 0, sizeof(illuminated));
    illuminated[0][0] = 1;
    int curX = 0, curY = 0, velX = 1, velY = 1;
    while(1)
    {
        curX += velX;
        curY += velY;
     
        illuminated[curX][curY] = 1;
 
        // Hits a corner
        if((curX == 0 || curX == n) && (curY == 0 || curY == m)) break;
        
        // Hits a wall
        if(curX == n or curX == 0) velX *= -1;
        if(curY == m or curY == 0) velY *= -1;      
    }
 
    int q; 
    cin >> q;
    while(q--)
    {
        int x, y; 
        cin >> x >> y;
        if(illuminated[x][y]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
