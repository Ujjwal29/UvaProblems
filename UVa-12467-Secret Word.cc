//String, KMP
#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pat, int n, int *lps)
{
	int len=0,i=1;
	lps[0]=0;
	while(i<n)
	{
		if(pat[i]==pat[len])
			lps[i++]=++len;

		else
		{
			if(len)
				len=lps[len-1];
			else
				lps[i++]=0;
		}
	}
}

void kmp(string txt)
{
	int n=txt.size();
	int lps[n];
	computeLPS(txt,n,lps);
	
	int i=0,j=0;
	int max_length = 0, max_i;
    for (int i = n - 1, j = 0; i >= 0; ) 
    {
		if (i >= 0 && txt[j] == txt[i])
        	j++, i--;
      	if (j > max_length)
        	max_length = j, max_i = i + 1;
      	if (j == n)
        	j = lps[j - 1];
      	else if (i >= 0 && txt[j] != txt[i]) 
      	{
        	if (j)
          		j = lps[j - 1];
        	else
          		i--;
      	}
    }
	
	txt[max_i + max_length]='\0';
	puts(&txt[max_i]);
}

int main()
{
	int tc;
	string s;
	scanf("%d",&tc);
	while(tc--)
	{
		cin >> s;
		// apply KMP algorithm 
    	// where patten is an input string and text is the reverse of the input string
    	// calculate lps[]
		kmp(s);
	}
}
