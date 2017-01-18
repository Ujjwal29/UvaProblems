#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;
vector<string> vs;
stack<int>Stack;

class Graph{
	int V;
	list<int> *adj;

	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

	public:
		Graph(int V);
		void addEdge(int v, int w);
		void topologicalSort();
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

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	visited[v]=true;
	for(auto i=adj[v].begin(); i!=adj[v].end(); i++)
		if(visited[*i]==false)
			topologicalSortUtil(*i, visited, Stack);
	Stack.push(v);

}

void Graph::topologicalSort()
{
	bool *visited = new bool[V];
	for(int i=0; i<V; i++)
		visited[i]=false;
	
	for(int i=0; i<V; i++)
		if(visited[i]==false)
			topologicalSortUtil(i, visited, Stack);
}

set<char> getDistinct()
{
	string str;
	set<char>s;
	while(true)
	{
		cin >> str;
		if(str == "#")
			break;
		vector<char> v(str.begin(), str.end());
		vs.pb(str);
		s.insert(v.begin(), v.end());
	}
	return s;
}

pair<char, char> edge(string s1, string s2)
{
	pair<char, char>p;
	p.first='#';
	p.second='#';

	int len = min(s1.length(), s2.length());
	for(int i=0; i<len; i++)
	{
		if(s1[i] != s2[i])
		{
			p.first = s1[i];
			p.second = s2[i];
			break;
		}
	}
	return p;
}

char character(int a, map<char, int>m)
{
	char c;
	for(auto i:m)
	{
		if(i.second == a)
		{
			c=i.first;
			break;
		}
	}
	return c;
}

int main()
{
	set<char> s;
	s = getDistinct();
	int set_size = s.size();
	
	map<char, int>m;
	int j=0;
	for(auto i=s.begin(); i!=s.end(); i++)
	{
		m[*i]=j;
		j++;
	}
	
	Graph g(set_size);
	for(int i=0; i<vs.size()-1; i++)
	{
		pair<char, char> p;
		p = edge(vs[i], vs[i+1]);

		if(p.first!='#' && p.second !='#')
			g.addEdge(m[p.first], m[p.second]);
	}

	g.topologicalSort();
	
	for(int i=0; i<set_size; i++)
	{
		char c = character(Stack.top(), m);
		cout<<c;
		Stack.pop();
	}
	cout<<endl;
}
