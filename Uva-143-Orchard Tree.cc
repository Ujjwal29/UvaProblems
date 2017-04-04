#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;
typedef struct{
	double x,y;
} Point;

bool Area(Point p0, Point p1, Point p2)
{
	double area = (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
	if(area<1e-6)
		return false;
	return true;
}

double onLeft(Point p0, Point p1, Point p2)
{
	return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}

bool PointInTriangle(Point p1, Point p2, Point p3, Point p)
{
	bool area = Area(p1,p2,p3);
	if(area)
	{
		if( (onLeft(p1,p2,p)>0 || onLeft(p1,p2,p)==0.0)&& 
			(onLeft(p2,p3,p)>0 || onLeft(p2,p3,p)==0.0)&& 
			(onLeft(p3,p1,p)>0 || onLeft(p3,p1,p)==0.0))
		{

			return true;
		}
		return false;
	}
	else
	{
		if( (onLeft(p2,p1,p)>0 || onLeft(p2,p1,p)==0.0)&& 
			(onLeft(p3,p2,p)>0 || onLeft(p3,p2,p)==0.0)&& 
			(onLeft(p1,p3,p)>0 || onLeft(p1,p3,p)==0.0))
		{

			return true;
		}
		return false;
	}
}

int main()
{
	while(1)
	{
		Point p1,p2,p3;
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		if(p1.x==0 && p1.y==0 && p2.x==0 && p2.y==0 && p3.x==0 && p3.y==0)
			break;
		
		int count=0;
		for(int i=1; i<100; i++)
		{
			for(int j=1; j<100; j++)
			{	
				Point p;
				p.x=double(i);p.y=double(j);
				if(PointInTriangle(p1,p2,p3,p))
					count++;
			}
		}
		/*
		string str=to_string(count);
		while(str.size()<4)
			str=" "+str;
		//cout<<str<<endl;
		*/
		printf("%4d\n", count);
	}
	cout<<endl;
}
