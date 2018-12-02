#include <bits/stdc++.h>
using namespace std;
int main()
{	long n;
	cin>>n;
	long a[n+1],count=1,max=1;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	a[n]=0;
	for (int i = 1; i <= n; ++i)
	{	if(a[i]>=a[i-1])
		{	count++;
		}
		else
		{
			//count+=1;
			if (count>max)
			{
				max=count;
			}
			count=1;
		}
		
	}
	cout<<max;




	return 0;
		
}