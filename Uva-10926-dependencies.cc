#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

vector<pair<int,int> >vec;
class Graph{
	int V;
	list<int> *adj;
	void dfsUtil(int v, bool visited[], vector<int>&Stack);

	public:
		Graph(int V);
		void addEdge(int u, int v);
		void dfs();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::dfsUtil(int v, bool visited[], vector<int>&Stack)
{
	visited[v]=true;
	Stack.pb(v);

	for(auto i = adj[v].begin(); i!=adj[v].end(); i++)
		if(!visited[*i])
			dfsUtil(*i, visited, Stack);
}

void Graph::dfs()
{
	vector<int>Stack;
	bool *visited = new bool[V];
	for(int i=1; i<V; i++)
		visited[i]=false;
	
	for(int i=1; i<V; i++)
	{
		for(int j=1; j<V; j++)
			visited[j]=false;
		Stack.clear();
		dfsUtil(i, visited, Stack);
		vec.pb(mp(Stack.size()-1, i));
	}
}

bool cmp(pair<int,int>a, pair<int,int>b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	int n,t,val;
	while(1)
	{
		vec.clear();
		cin >> n;
		if(n==0)
			break;
		
		Graph g(n+1);
		for(int i=1; i<=n; i++)
		{
			cin >> t;
			while(t--)
			{
				cin >> val;
				g.addEdge(i,val);
			}
		}
		g.dfs();
		sort(vec.begin(), vec.end(), cmp);
		cout<<vec[0].second<<endl;
	}
}
