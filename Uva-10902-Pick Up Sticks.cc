#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef struct {float x,y;} Point;
typedef struct {Point p1,p2;} Segment;

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n==0) break;
		vector<pair<Segment,int> >v;

		for(int i=1; i<=n; i++)
		{
			Segment s;
			cin >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;
			v.pb(mp(s,i));
		}
		
		int i=0;
		int a[v.size()];
		for(int k=0; k<v.size(); k++)
			a[k]=0;

		while(i<v.size())
		{
			int j=i+1;
			while(j<v.size())
			{
				if(doIntersect(v[i].first.p1, v[i].first.p2, v[j].first.p1, v[j].first.p2))
				{
					a[i]=1;
					break;
				}
				j++;
			}
			i++;
		}

		
		cout<<"Top sticks: ";
		for(i=0; i<v.size()-1; i++)
			if(a[i]==0)
				printf("%d, ",v[i].second);
		printf("%d.\n",v[i].second);
		
	}
	//cout<<endl;
}
