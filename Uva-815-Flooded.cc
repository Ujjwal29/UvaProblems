#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	int region=1;
	vector<int>v;
	while(1)
	{
		int m,n,val;
		if(region>1)
			printf("\n");;
		scanf("%d %d",&m,&n);
		if(m==0 && n==0)
			break;
		
		double cubic_meter,filled_area=0,remaining_area=0,height=0;
		int i=0,j=1,count=1;
		v.clear();
				
		for(int k=0; k<m*n; k++)
		{
			cin >> val;
			v.pb(val);
		}
		scanf("%lf",&cubic_meter);
		sort(v.begin(), v.end());
		
		while(filled_area < cubic_meter)
		{
			if(v.size()==1 || count==v.size())
				break;
			double nextFill = abs((v[j]-v[i]))*count*100;
			filled_area += nextFill;
			i++;j++;count++;
			if(filled_area==cubic_meter)
				count--;
			if(filled_area > cubic_meter)
			{
				filled_area -= nextFill;
				count--;i--;
				break;
			}
		}

		height = v[i];
		if(filled_area < cubic_meter)
		{
			remaining_area = cubic_meter-filled_area;
			height = height + (remaining_area)/(double(count)*100);
		}
		
		double percent_region = (double(count)/double(m*n))*100;
		printf("Region %d\n",region);
		printf("Water level is %.2lf meters.\n",height);
		printf("%.2lf percent of the region is under water.\n",percent_region);
		region++;
	}
}
