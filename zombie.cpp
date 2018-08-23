#include <bits/stdc++.h>
using namespace std;
int main()
{	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int x,y,z,a,b,flag=0;
	cin>>x>>y>>z;
	if (y>x)
	{	int temp=x;
		x=y;
		y=temp;
	}
	a=z/x;
	b=0;
	while(a>=0 && a<=z/x && b>=0 && b<=z/y )
	{	if (a*x+b*y==z)
		{	flag=1;
		 	cout<<"Yes";
		 	break;
		}
		if (a*x+b*y<z)
		{
			b+=1;
		}
		if (a*x+b*y>z)
		{
			a-=1;
		}

	}
	if (flag==0)
	{
		cout<<"No";
	}
	


	return 0;
}