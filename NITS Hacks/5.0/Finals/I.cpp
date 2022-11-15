#include <bits/stdc++.h>
using namespace std;
 
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
 
typedef vector <int> vi;
typedef pair <int, int> pii;
 
const int N = (int)3e6;
 
struct edge
{
  int a, b, l, r;
};
typedef vector <edge> List;
 

int cnt[N + 1], ans[N], u[N], color[N], deg[N];
vi g[N]; // adjacency list of graph
 
// adds edge a-b to adjacency list
void add( int a, int b )
{
  g[a].pb(b), g[b].pb(a);
}
 
void dfs( int v, int value )
{
  u[v] = 1, color[v] = value;
  forn(i, sz(g[v]))
    if (!u[g[v][i]]) // if g[v][i] has not been visited 
      dfs(g[v][i], value);
}
 

void go( int l, int r, const List &v, int vn, int add_vn ) // [l, r)
{
  if (cnt[l] == cnt[r])
    return; // no queries, only changes
  if (!sz(v))
  {
    while (l < r)
      ans[l++] = vn + add_vn;
    return;
  }  
 
  List v1; // new list of edges with interval
  forn(i, vn) // vn is no. of nodes
    g[i].clear(); // clearing g[i] for node u
  forn(i, sz(v))
    if (v[i].a != v[i].b)
    {
      if (v[i].l <= l && r <= v[i].r) // if [v[i].l, v[i].r] is superset [l,r] of  then add the edge 
        add(v[i].a, v[i].b);
      else if (l < v[i].r && v[i].l < r) // if [v[i].l, v[i].r] is subset of [l,r] then add it to v1 to be processed later 
        v1.pb(v[i]);
    }
 
  // Finding the connected components then compressing it
  //--------------------------------------------------------
  int vn1 = 0; // new no. of nodes
  forn(i, vn)
    u[i] = 0;
  forn(i, vn)
    if (!u[i])
      deg[vn1] = 0, dfs(i, vn1++); // finding cc of i and coloring them with vn1
 
  // updating vertices of the edges with new vertices 
  forn(i, sz(v1))
  {
    v1[i].a = color[v1[i].a];
    v1[i].b = color[v1[i].b];
    if (v1[i].a != v1[i].b)
      deg[v1[i].a]++, deg[v1[i].b]++;
  }
 
  vn = vn1, vn1 = 0;
  forn(i, vn)
    u[i] = vn1, vn1 += (deg[i] > 0), add_vn += !deg[i];
  forn(i, sz(v1))
  {
    v1[i].a = u[v1[i].a];
    v1[i].b = u[v1[i].b];
  }
  //--------------------------------------------------------

  int m = (l + r) / 2; // [l, m) [m, r)
  go(l, m, v1, vn1, add_vn);
  go(m, r, v1, vn1, add_vn);
}
 

vector<int> solve(int n, vector<tuple<char,int,int>> queries)
{
  // n: no. of nodes
  // k: no. of queries
  int k = queries.size();

  map <pii, int> m; // m stores stores edges and query at which x-y is added
  List v; // list of edges with interval
  
  forn(i, k)
  {
    char type;
    int a, b;
    tie(type, a, b) = queries[i];
    a--; b--; // 0-indexed nodes

    if (type == '+' || type == '-')
    {
      if (a > b)
        swap(a, b);
 
      if (type == '+')
        m[mp(a, b)] = i;
      else
      {
        int &j = m[mp(a, b)];
        v.pb({a, b, j, i}); // edge a-b is present from time j to time i
        j = -1;
      }
    }
    else
      cnt[i + 1]++; // cnt[i]: count of type ? queries till ith query
    cnt[i + 1] += cnt[i]; 
  }
  forit(it, m) // iterate on all edges
    if (it->second != -1) // the edge was not removed 
      v.pb({it->first.first, it->first.second, it->second, k}); // edge a-b is present from time j = m[{a,b}] to k
 
  // solve for range [0, k]
  go(0, k, v, n, 0);
 
  vector<int> res;
  forn(i, k)
    if (cnt[i + 1] != cnt[i]) // if type ? query
      res.pb(ans[i]); // printf("%d\n", ans[i]);

  return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m; 
    cin >> n >> m;
    int q; 
    cin >> q;
    vector<tuple<int,int,int,int,int>> queries;
    for(int i = 0; i < q; i++)
    {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        queries.pb({t,x1,y1,x2,y2});
    }

    // convert cells to nodes
    map<pair<int,int>, int> node;
    int nd = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            node[{i,j}] = ++nd;

    // convert queries into graph edge addition / removal queries
    vector<tuple<char,int,int>>  graph_queries;
    for(int i = 0; i < q; i++)
    {
        int t, x1, y1, x2, y2;
        tie(t,x1,y1,x2,y2) = queries[i];
        char ch = (t == 1)? '+' : '-';
        if(x1 == x2) // column
        {
            for(int yi = y1, yj = y2; yi < yj; yi++, yj--)
            {
                graph_queries.pb({ch, node[{x1,yi}], node[{x1,yj}]});
            }
        }
        else if(y1 == y2) // row
        {
            for(int xi = x1, xj = x2; xi < xj; xi++, xj--)
            {
                graph_queries.pb({ch, node[{xi,y1}], node[{xj,y1}]});
            }
        }
        graph_queries.pb({'#', -1, -1}); // print query
    }

    vector<int> res = solve(nd, graph_queries);

    // subtract extra value from res due to unvisited cells in the crossword grid
    map<pair<int, int>,int> vis;
    for(int i = 0; i < q; i++)
    {
        int t, x1, y1, x2, y2;
        tie(t,x1,y1,x2,y2) = queries[i];
        if(x1 == x2) // column
        {
            for(int y = y1; y <= y2; y++)
            {
                if(t == 1) vis[{x1,y}]++;
                else 
                {
                    vis[{x1,y}]--;
                    if(vis[{x1,y}] == 0) vis.erase({x1,y});
                }
            }
        }
        else if(y1 == y2) // row
        {
            for(int x = x1; x <= x2; x++)
            {
                if(t == 1) vis[{x,y1}]++;
                 else 
                {
                    vis[{x,y1}]--;
                    if(vis[{x,y1}] == 0) vis.erase({x,y1});
                }
            }
        }

        int unvis = n*m - vis.size();
        res[i] -= unvis;
    }

    // Printing answer for each query
    for(auto x: res) cout << x << endl;
    return 0;
}
