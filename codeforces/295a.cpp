#include <bits/stdc++.h>
using namespace std;
class Operation{
public:
	long l;
	long r;
	unsigned long long d;
};
int main()
{	long n,m,k,x,y;
	cin>>n>>m>>k;
	unsigned long long a[n+1],temp;
	for (long i = 1; i < n+1; ++i)
	{
		cin>>a[i];
	}
	Operation o[m+1];
	long freq[m+1]={0};
	//storing the operations
	for (long i = 1; i <=m; ++i)
	{
		cin>>o[i].l;
		cin>>o[i].r;
		cin>>o[i].d;
	}
	//inputting the queries
	while(k--)
	{
		cin>>x>>y;
		freq[x]+=1;
		if (y < m)
		{
			freq[y+1]=freq[y+1]-1;
		}
	}
	temp=0;
	for (long i = 1; i <= m ; ++i)
	{
		temp+=freq[i];
		freq[i]=temp;
		o[i].d= o[i].d*freq[i];
	}
	//manipulating the array 
	unsigned long long final_freq[n+1]={0};
	for (long i = 1; i <= m; ++i)
	{
		final_freq[o[i].l]+=o[i].d;
		if (o[i].r < n)
		{
			final_freq[(o[i].r) +1] = final_freq[(o[i].r) +1] - o[i].d;
		}
	}
	temp=0;
	for (long i = 1; i <= n ; ++i)
	{	temp+=final_freq[i];
		//final_freq[i]=temp;
		a[i]+=temp;
		
	}
	for (long i = 1; i <= n; ++i)
	{
		cout<<a[i]<<" ";
	}

}