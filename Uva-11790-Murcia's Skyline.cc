#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;
vector<int>height;
vector<int>width;
int tc,m,val;

int LIS(vector<int>height, vector<int>width)
{
	int maxx=0,n=height.size();
	vector<int>lis(n);;

	for(int i=0; i<n; i++)
		lis[i]=width[i];

	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(height[i]>height[j] && lis[i]<lis[j]+width[i])
				lis[i]=lis[j]+width[i];
	
	return *max_element(lis.begin(), lis.end());
}

void print(int inc, int dec, int k)
{
	if(inc >= dec)
		printf("Case %d. Increasing (%d). Decreasing (%d).\n",k,inc,dec);
	
	else
		printf("Case %d. Decreasing (%d). Increasing (%d).\n",k,dec,inc);
}

int main()
{
	cin >> tc;
	for(int k=1; k<=tc; k++)
	{
		cin >> m;
		height.clear();
		width.clear();

		for(int i=0; i<m; i++)
		{
			cin >> val;
			height.pb(val);
		}
		
		for(int i=0; i<m; i++)
		{
			cin >> val;
			width.pb(val);
		}

		int increasing = LIS(height, width);
		reverse(height.begin(), height.end());
		reverse(width.begin(), width.end());
		int decreasing = LIS(height, width);
		
		print(increasing, decreasing, k);
	}
}
