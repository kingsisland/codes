#include <bits/stdc++.h>
using namespace std;
unsigned long long b,a[200005],temp;
long n,mid;
int main()
{	
	cin>>n;
	mid=n/2;
	cin>>b;  //first b1
	a[1]=0;
	a[n]=b;
	for (long  i = 2; i <= mid ; ++i)
	{	cin>>b;
		
			a[i]=a[i-1];
			b=b-a[i];
			if(b> a[n-i+2])
			{
				a[n-i+1]=a[n-i+2];
				b=b-a[n-i+1];
				a[i]+=b;
			}
			else
				a[n-i+1]=b;

		
	}

	for (long i = 1; i <= n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";

	return 0;
}