
#include <bits/stdc++.h>
using namespace std;
int a[1005],lit[1005]={0};


int main()
{	int n,r,count=0,sum=0,fr[1005],j=0,s,flag=0,low;
	cin>>n>>r;
	//s=0;
	for (int i = 1; i <=n; ++i)
	{
		cin>>a[i];

	}
	int i=1,m;
	while(i<=n)
	{	
		s=i+r-1;

		if(s>n)
		{
			s=n;
		}
		low=i-r+1;
		if(low<1)
		{
			low=1;
		}
		//cout<<"\n  i: "<<i<<" s: "<<s<<endl;
		flag=0;
		for ( m = s; m >=low  ; --m)
		{	if(a[m]==1)
			{	//cout<<"\n Heater at : "<<m<<endl;
				count++;
				flag=1;
				
				break;

			}
		}
		if(flag==0)
		{		
			// if(fr[i]==0)
			// {	fr[i]=1;
			// 	i=i-r+1;
			// 	if(i<1)
			// 	{
			// 		i=1;
			// 	}
			// 	fr[i]=1;
			// 	continue;
			// }
			// else
			// {	
			// 	break;
			// }
			break;	
		}
	
			for (; i <= (m+r-1) && i<=n; ++i)
			{
				lit[i]=1;
			

			}		
		
	}
	//cout<<endl;
	for (int i = 1; i <= n; ++i)
	{
		//cout<<lit[i]<<" ";
		sum+=lit[i];
	}
	//cout<<endl;
	if (sum==n)
	{
		cout<<count<<endl;
	}
	else
		cout<<"-1\n";

	


	
	return 0;
}