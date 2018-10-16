#include <bits/stdc++.h>
using namespace std;
int a[1005],lit[1005]={0};


int main()
{	int n,r,min,max,count=1,sum=0,pos[1005],j=0;
	cin>>n>>r;
	for (int i = 1; i <=n; ++i)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			pos[j]=i;
			j++;
		}
		

	}		
		if(pos[0]>0)
		{
			//for first lantern
			min=pos[0]-r+1;
			if(min<0) min=1;
			max=pos[0]+r-1;
			if(max>n) max=n;
			for (int i = min; i <= max; ++i)
			{
				lit[i]=1;
			}
		}
		
	for (int i = 1; i <j; ++i)
	{	
		
			min=pos[i]-r+1;
			if(min<0) min=1;
			max=pos[i]+r-1;
			if(max>n) max=n;
			if (pos[i-1]>=min && pos[i+1]<= max)
			{
				
			}
			else
			{	count++;
				//cout<<"\n pos of lantern : "<<pos[i]<<endl;
				for (int i = min; i <= max; ++i)
				{
					if (lit[i]==0)
					{
						lit[i]=1;
					}
				}
			}
		}
		cout<<endl;
		for (int i = 1; i <=n ; ++i)
		{
		 	sum+=lit[i];
		 	cout<<lit[i]<<" ";
		}
		cout<<endl;
		if(sum<n)
		{
			cout<<"-1";
		}
		else 
			cout<<count;
	
	
	return 0;
}