#include <bits/stdc++.h>
using namespace std;
int a[105],ones[105]={0};
int flipping(int n)
{
	int max=0,zeroes,tot;

	for (int i = 1; i <=n; ++i)
	{
		for (int j = i; j <= n ; ++j)
		{	tot=0;    
			zeroes=(j-i+1)-(ones[j]-ones[i]+a[i]);
				if(i>1)
				{
					tot+=ones[i-1]-ones[1]+a[1];
				}
				if (j<n)
				{
					tot+=ones[n]-ones[j+1]+a[j+1];
				}
				tot+=zeroes;
				if(tot>max)
				{
					max=tot;
				}
			
		}
	}
	/*if(ones[n]-ones[1]+a[1]>max)
	{
		return ones[n]-ones[1]+a[1];
	}*/
	return max;
}


int main()
{	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{	cin>>a[i];
		ones[i]=ones[i-1]+a[i];
	}

	cout<<flipping(n);


	return 0;
}