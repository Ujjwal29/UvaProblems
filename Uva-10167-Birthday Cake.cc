#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;
typedef struct{
	int x,y;
} Point;

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n==0) break;
		vector<Point>v;
		for(int i=0; i<2*n; i++)
		{
			Point p;
			cin >> p.x >> p.y;
			v.pb(p);
		}
		int i,j,one,two;
		for(i=-500; i<=500; i++)
		{
			for(j=-500; j<=500; j++)
			{
				one=0,two=0;
				for(auto p:v)
				{	
					int temp = i*p.x + j*p.y;
					if(temp > 0) one++;
					else if(temp < 0) two++;
				}
				if(one==n && two==n)
					break;
			}
			if(one==n && two==n)
				break;
		}
		cout<<i<<" "<<j<<endl;
	}
}
