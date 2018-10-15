#include <bits/stdc++.h>
using namespace std;
int main()
{	long n,sum=0,temp;
	cin>>n;
	long a[n+1],t[n+1];
	//int flag=0;
	for (long i = 1; i <=n; ++i)
	{	cin>>t[i];
		temp=t[i];
		sum+=temp;
		a[i]=sum;
	}
	temp=0;
	sum=0;
	for (long i = 1; i <n ; ++i)
	{
		for (long j = n; j >= i; --j)
		{	sum=a[j]-a[i]+t[i];
			if(sum > (j-i+1)*100)
			{
				
				if(temp< (j-i+1))
				{	//cout<<"\n Updated temp i: "<<i<<" and j: "<<j<<endl;
					temp=j-i+1;
				}


			}	
			
		}
	}
	cout<<temp;
	return 0;
}