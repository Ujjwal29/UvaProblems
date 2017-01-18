#include<bits/stdc++.h>
using namespace std;

#define max_x 1024
#define max_y 1024

// mat - 2D Binary Index tree
long mat[max_x][max_y];

int getParent(int index)
{
	return index - (index & -index);
}

int getNext(int index)
{
	return index + (index & -index);
}

void update(int x , int y , int val, int s){
    int y1;
    while (x <= s)
    {
        y1 = y;
        while (y1 <= s)
        {
            mat[x-1][y1-1] += val;
            y1 = getNext(y1);
        }
        x = getNext(x);
    }
}

int read(int x,int y)
{ // return sum from 1,1 to x,y.
	int sum= 0;        
	while(x>0)
	{
		int y1 = y;
		while(y1>0)
		{
			sum += mat[x-1][y1-1];
		    y1 = getParent(y1);;
		}
		x = getParent(x);
	}
	return sum;
}

int main()
{
	int qtype,s,x,y,l,b,r,t;
    int a;
    cin >> qtype >> s;
    memset(mat, 0, sizeof(mat));
	
    while(true)
    {
    	cin >> qtype;
    	
    	if(qtype==1)
       	{
			cin >> x >> y >> a;
			update(x+1, y+1, a, s);
			
			/*
			for(int i=0; i<s; i++)
			{
				for(int j=0; j<s; j++)
					cout<<mat[i][j]<<" ";
				cout<<endl;
			}
			*/
	   	}
    	
    	else if(qtype==2)
    	{
    		cin >> l >> b >> r >> t;
			int ans = 0;
			ans = read(r+1, t+1) - read(l, t+1) - read(r+1, b) + read(l, b); 
			//ans = read(r, t) - read(l, t) - read(r, b) + read(l, b); 
			cout<<ans<<endl;
     	}
    	
    	else if(qtype==3)
    		break;
    }
}
