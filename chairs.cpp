#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long mod=MOD;


long power(unsigned long long n)
{
	long res=1,x=2;
	while(n>0)
	{
		if (n%2==1)
		{
			res= (res*x%mod)%mod;	
		}
		n=n/2;
		x=((x%mod)*(x%mod))%mod;	
	}
	return res;
}

int main()
{
	long t;
	unsigned long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<power(n)-2<<"\n";

	}
	return 0;
}