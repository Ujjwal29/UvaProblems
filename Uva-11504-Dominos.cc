#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;
vector<int>vec;

class Graph{
	int V;
	list<int> *adj;
	void dfsUtil(int v, vector<bool>&visited);
	void dfsUtilReverse(int v, vector<bool>&visited);

	public:
		Graph(int V);
		void addEdge(int v, int w);
		void dfs();
		void dfsReverse();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].pb(w);
}

void Graph::dfsUtil(int v, vector<bool>&visited)
{
	visited[v]=true;
	for(auto i=adj[v].begin(); i!=adj[v].end(); i++)
		if(visited[*i]==false)
			dfsUtil(*i, visited);
	vec.pb(v);
}

void Graph::dfs()
{
	vector<bool>visited(V,false);	
	for(int i=0; i<V; i++)
	{
		if(visited[i]==false)
			dfsUtil(i, visited);
	}
}

void Graph::dfsUtilReverse(int u, vector<bool>&visited)
{
	visited[u]=true;
	for(auto i=adj[u].begin(); i!=adj[u].end(); i++)
		if(visited[*i]==false)
			dfsUtil(*i, visited);
}

void Graph::dfsReverse()
{
	vector<bool>visited(V,false);
	int comp=0;
	for(int i=0; i<V; i++)
	{
		int u=vec[i];
		if(!visited[u])
		{
			dfsUtilReverse(u,visited);
			comp++;
		}
	}
	cout<<comp<<endl;
}

int main()
{
	int tc,u,v,n,m;
	cin >> tc;
	while(tc--)
	{
		vec.clear();
		cin >> n >> m;
		Graph g(n);
		for(int i=0; i<m; i++)
		{
			cin >> u >> v;
			g.addEdge(u-1,v-1);
		}
		g.dfs();
		reverse(vec.begin(), vec.end());
		g.dfsReverse();
	}
}
