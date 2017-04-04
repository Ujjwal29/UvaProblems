#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

bool mycomparator(pair <double,int> a, pair <double, int> b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	else
		return (a.first > b.first);
}

int main()
{
	int n,teams;
	cin >> n;
	teams = pow(2,n);
	double a[teams][teams];

	for(int i=0; i<teams; i++)
	{
		for(int j=0; j<teams; j++)
		{
			cin >> a[i][j];
			a[i][j] *= 0.01;
		}
	}

	double winProb[teams][n+1];
	for (int team=0; team<teams; team++)
		winProb[team][1] = a[team][team^1];
	
	for(int round = 2; round<=n; round++)
	{
		for(int team = 0; team<teams; team++)
		{
			for(int i = pow(2,round-1); i<pow(2, round); i++)
			{
				winProb[team][round] += a[team][team^i]*winProb[team^i][round-1];
			}
			winProb[team][round]*=winProb[team][round-1];
		}
	}

	vector< pair<double, int> > v;
	for(int i=0; i<teams; i++)
		v.pb(mp(winProb[i][n], i));
	
	sort(v.begin(), v.end(), mycomparator);

	for(int i=0; i<v.size(); i++)
		cout<<v[i].second+1<<endl;
}
