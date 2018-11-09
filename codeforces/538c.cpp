#include <bits/stdc++.h>
using namespace std;
long d[100005],h[100005],Max=-1,tempm;
int main()
{	long n,m;
	int flag=0;
	cin>>n>>m;
	for(long i=1;i<=m;i++)
	{
		cin>>d[i]>>h[i];
	}
	// if(d[1] > 1)
	// {
	// 	if(h[1] <= d[1]-1 )
	// 	{ 	tempm=((h[1])+(d[1]-2));
	// 		if(tempm%2!=0)
	// 		{
	// 			tempm=tempm/2;
	// 			tempm++;
	// 		}
	// 		else
	// 		{
	// 			tempm=tempm/2;
	// 		}
	// 		if(tempm>Max)
	// 		{
	// 			Max=tempm;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		cout<<"IMPOSSIBLE\n";
	// 		flag=1;
	// 	}
	// }
	Max=h[1]+d[1]-1;
	if(flag==0)
	{
		for(long i=2;i<=m;i++)
		{
			if(h[i] <= h[i-1]+d[i]-d[i-1] && h[i]>= h[i-1]-d[i]+d[i-1])
			{	tempm=((h[i]-h[i-1])+(d[i]-d[i-1]-1));
				if(tempm > 0)
				{
					if(tempm%2!=0 )
					{	
						tempm=tempm/2;
						tempm++;
					}
					else
					{
						tempm=tempm/2;
					}
					if(h[i-1]+tempm > Max)
					{	//cout<<"\n temp: "<<tempm;
						Max=h[i-1]+tempm;
						//cout<<"\n i: "<<i<<" max: "<<Max<<"\n";
					}
				}
				else
				{
					if(h[i-1]>Max)
					{
						Max=h[i-1];
					}
				}

			}
			else
			{
				cout<<"IMPOSSIBLE\n";
				flag=1;
				break;
			}
		}
		if(n-d[m]+h[m] > Max /*&& d[m]< n*/)
		{
			Max=n-d[m]+h[m];
		}
	}


	
	if(flag!= 1)
	{
		cout<<Max<<"\n";
	}


	return 0;
}