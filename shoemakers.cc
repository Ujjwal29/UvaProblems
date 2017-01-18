#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

bool comparator(pair<double, int> a, pair<double, int> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	else 
		return a.first > b.first;
}

int main()
{
	int tc,n,t,s;
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		vector<pair<double, int> >v;
		for(int i=1; i<=n; i++)
		{
			cin >> t >> s;
			double val = double(s)/double(t);
			v.pb(mp(val,i));
		}

		sort(v.begin(), v.end(), comparator);
		for(int i=0; i<v.size(); i++)
		{
			cout<<v[i].second;
			if(i<v.size()-1)
				cout<<" ";
		}
		cout<<"\n";
		if(tc)
			cout<<endl;
	}
}
