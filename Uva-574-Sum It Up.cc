#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
	int t,n;
	while(true)
	{
		cin >> t >> n;
		if(n==0)
			break;

		int a[n];
		for(int i=0; i<n; i++)
			cin >> a[i];
		
		set<vector<int> >v;
		for(int i=0; i<pow(2,n); i++)
		{
			string binary = bitset<12>(i).to_string();
			binary = binary.substr(12-n, n);
			vector<int>temp;
			for(int j=0; j<binary.length(); j++)
			{
				if(binary[j]=='1')
					temp.pb(a[j]);
			}
			
			v.insert(temp);	
		}
		
		vector<vector<int> >ans;
		for(auto vec : v)
		{
			int sum_of_elems = accumulate(vec.begin(), vec.end(), 0);
			if(sum_of_elems == t)
				ans.pb(vec);
		}

		cout<<"Sums of "<<t<<":"<<endl;
		
		if(ans.size()==0)
			cout<<"NONE"<<endl;
		else
		{
			for(int i=ans.size()-1; i>=0; i--)
			{
				if(ans[i].size()==1)
					cout<<ans[i][0]<<endl;
				else
				{
					for(int j=0; j<ans[i].size(); j++)
					{
						cout<<ans[i][j];
						if(j!=ans[i].size()-1)
							cout<<"+";
					}
					cout<<endl;
				}
			}
		}
	}
}
