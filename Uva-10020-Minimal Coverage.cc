#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

bool mycomparator(pair<int, int>a, pair<int, int>b)
{
	if(a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}

int main()
{
	int tc,x,y,m;
	cin >> tc;
	while(tc--)
	{
		cin >> m;
		vector< pair<int, int> >v;
		while(true)
		{
			cin >> x >> y;
			if(x==0 && y==0)
				break;
			else 
				v.pb(mp(x,y));
		}
		
		sort(v.begin(), v.end(), mycomparator);
		
		int currentL=0, maxR=0;
		vector< pair<int, int> >ans;
		int i=0;
		while(maxR < m)
		{
			//pick the one with the longest range and L <= currentL
			int newL = currentL;
			int index=-1;
			for(; i<v.size(); i++)
			{
				if(v[i].first > currentL)
					break;
				
				else if(v[i].second >= newL)
				{
					newL = v[i].second;
					index=i;
				}
				
			}
			
			if(index==-1)
				break;
			
			maxR = v[index].second;
			ans.pb(v[index]);
			currentL = v[index].second;

		}
		if(maxR>=m)
		{
			cout<<ans.size()<<endl;
			for(auto p:ans)
				cout<<p.first << " "<< p.second<<endl;
		}
		else
			cout<<0<<endl;
		
		if(tc)
			cout<<endl;
	}
}
