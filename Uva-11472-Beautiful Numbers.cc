#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define MOD 1000000007

using namespace std;
int N,M;
int dp[101][1025][11];

int searchNext(int len, int lastDigit, int mask)
{
	if(len > M)
		return 0;
	
	if(dp[len][mask][lastDigit]!=-1)
		return dp[len][mask][lastDigit];
	
	int bNumbers=0;
	if(mask == (1<<N)-1)
		bNumbers++;
	
	for(int nextDigit=lastDigit-1; nextDigit<=lastDigit+1; nextDigit+=2)
	{
		if(nextDigit < 0 || nextDigit >= N) continue;

		bNumbers += searchNext(len+1, nextDigit, mask | (1 << nextDigit));
		bNumbers %= MOD;
	}
	
	dp[len][mask][lastDigit] = bNumbers;
	return bNumbers;
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> N >> M;
		memset(dp, -1, sizeof(dp));
		int bNumbers=0;
		for(int digit =1; digit <= N-1; digit++)
		{
			bNumbers+=searchNext(1, digit, 1<<digit);
			bNumbers %= MOD;
		}
		cout<<bNumbers<<endl;
	}
}
