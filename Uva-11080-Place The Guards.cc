#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

class City
{
	int V,E,guards;
	pair<vector<int>, int> adj[];
	/*bool cmp(pair<vector<int>, int> &a, pair<vector<int>, int> &b)
	{ return (a.first.size() > b.first.size());}
	*/
	public:
	City(int V, int E);
	void addEdge(int u, int v);
	void bfs();
};
	
City::City(int V, int E)
{
	this->V = V;
	this->E = E;
	guards=0;
}

void City::addEdge(int u, int v)
{
	adj[u].first.pb(v);
	adj[v].first.pb(u);
}

/*
bool City::cmp(const pair<vector<int>, int> &a, const pair<vector<int>, int> &b) 
{
	return (a.first.size() > b.first.size());
}
*/

void City::bfs()
{
	bool guarded[V];
	for(int i=0; i<V; i++)
	{
		guarded[i]=false;
		adj[i].second=i;
	}
	//sort(adj.begin(), adj.end(), cmp);
	//sort(begin(adj), end(adj), cmp);
	//sort(adj, adj+V);
	
	for(int i=0; i<V; i++)
	{
		int u = adj[i].second;
		if(!guarded[u])
		{
			guarded[u]=true;
			guards++;
			vector<int>vec(adj[i].first.begin(), adj[i].first.end());
			bool notPossible=false;
			for(int j=0; j<vec.size(); j++)
			{
				if(guarded[vec[j]])
				{
					notPossible=true;
					break;
				}
				guarded[vec[j]]=true;
			}

			if(notPossible)
			{
				guards=-1;
				break;
			}
		}
	}
	printf("%d\n", guards);
}

int main()
{
	int tc,nodes,edges,u,v;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d",&nodes, &edges);
		City c(nodes,edges);
		while(edges--)
		{
			scanf("%d %d",&u, &v);
			c.addEdge(u,v);
		}

		c.bfs();
	}
}
