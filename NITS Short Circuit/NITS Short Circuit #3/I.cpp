#include<bits/stdc++.h>
using namespace std;
 
#define NIL 0
#define INF INT_MAX
 
// Hopcroft Karp algorithm for Maximum Bipartite Matching - O(E√V)
// 1-indexed graph
class BipGraph
{
	int m, n;
	list<int> *adj;
	int *pairU, *pairV, *dist;
 
    public:
	BipGraph(int m, int n); 
	void addEdge(int u, int v); 
 
	bool bfs();
	bool dfs(int u);
	int hopcroftKarp();
};
 
int BipGraph::hopcroftKarp()
{
	pairU = new int[m+1];
	pairV = new int[n+1];
	dist = new int[m+1];
 
	for (int u = 0; u <= m; u++)
		pairU[u] = NIL;
	for (int v = 0; v <= n; v++)
		pairV[v] = NIL;
 
	int result = 0;
	while (bfs())
	{
		for (int u = 1; u <= m; u++)
			if (pairU[u] == NIL && dfs(u))
				result++;
	}
    return result;
}
 
// Returns true if there is an augmenting path
bool BipGraph::bfs()
{
	queue<int> Q;
	for (int u=1; u<=m; u++)
	{
		if (pairU[u]==NIL)
		{
			dist[u] = 0;
			Q.push(u);
        }
		else dist[u] = INF;
	}
 
	dist[NIL] = INF;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (dist[NIL]!=INF) break;
		for (auto v: adj[u])
		{
			if (dist[pairV[v]] == INF)
			{
				dist[pairV[v]] = dist[u] + 1;
				Q.push(pairV[v]);
			}
		}
	}
	return (dist[NIL] != INF);
}
 
// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(int u)
{
	if (u == NIL) return true;
	for (auto v: adj[u])
	{
		if (dist[pairV[v]] == dist[u]+1)
		{
			if (dfs(pairV[v]) == true)
			{
				pairV[v] = u;
				pairU[u] = v;
				return true;
			}
		}
	}
	dist[u] = INF;
	return false;
}
 
// Constructor
BipGraph::BipGraph(int m, int n)
{
	this->m = m;
	this->n = n;
	adj = new list<int>[m+1];
}
 
// To add edge from u to v and v to u
void BipGraph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}
 
 
void solve()
{
    int n, m; 
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) 
        cin >> s[i];
 
    // Consider the grid to be a chess board
    int index[n][m];
    int w = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // White non-missing cells
            if(s[i][j] == '0' && (i + j) % 2 == 0)
                index[i][j] = ++w;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // Black non-missing cells
            if(s[i][j] == '0' && (i + j) % 2 == 1)
                index[i][j] = ++b;
        }
    }
 
    BipGraph g(w, b);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '0')
            {
                if(i - 1 >= 0 && s[i - 1][j] == '0')
                {
                    if((i + j) % 2 == 0)
                        g.addEdge(index[i][j], index[i - 1][j]);
                    else
                        g.addEdge(index[i - 1][j], index[i][j]);
                }
                if(j - 1 >= 0 && s[i][j - 1] == '0')
                {
                    if((i + j) % 2 == 0)
                        g.addEdge(index[i][j], index[i][j - 1]);
                    else
                        g.addEdge(index[i][j - 1], index[i][j]);
                }
            }            
        }
    }
 
    // Answer = min vertex cover = max bipartite matching
    int ans = g.hopcroftKarp();
    cout << ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) solve();
}
