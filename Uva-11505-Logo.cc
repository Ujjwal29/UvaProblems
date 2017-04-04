#include<bits/stdc++.h>
#define pb push_back
#define sq(x) (x)*(x)
#define PI 3.14159265
using namespace std;
typedef struct{ double x,y;} Point;

int round_int( double r ) {
	return (r > 0.0) ? (r + 0.5) : (r - 0.5); 
}

int main()
{
	int tc,n;
	Point pos;
	double slope,d;
	string command;
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		pos.x=0;pos.y=0;slope=0;
		while(n--)
		{
			cin >> command >> d;
			if(command[0]=='f')
			{
				pos.x = pos.x + double(double(cos(slope*M_PI/180.0))*d);
				pos.y = pos.y + double(double(sin(slope*M_PI/180.0))*d);
			}
			
			else if(command[0]=='b')
			{
				pos.x = pos.x - double(double(cos(slope*M_PI/180.0))*d);
				pos.y = pos.y - double(double(sin(slope*M_PI/180.0))*d);
			}
			
			else if(command[0] == 'r')
				slope+=d;
			
			else
				slope-=d;
		}
		printf("%.lf\n",nearbyint(sqrt(sq(pos.x)+sq(pos.y))));
	}
}
