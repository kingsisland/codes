#include <bits/stdc++.h>
using namespace std;

int main()
{
	long n,max1,max2,min1,min2;
	cin>>n;
	long a[n];
	for (long i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	if(n==2)
	{
		cout<<'0';
	}
	else
	{
		sort(a,a+n);

	
	min1 = a[0];
	min2 = a[1];
	max1 = a[n-1];
	max2 = a[n-2];
	if(max1 - min2 <= max2 - min1)
	{
		cout<<max1 - min2;
	}
	else
	{
		cout<<max2 - min1;
	}
	}
	return 0;
}