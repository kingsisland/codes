#include <bits/stdc++.h>
using namespace std;
long dp[2005][2005]={0};
long a[2005];
long n,MIN=300000;
long cnt1=0;
bool flag=false;

long simpleGCD (long a, long b)
{	if(a<b)
	{
		long temp;
		temp=a;
		a=b;
		b=temp;
	}
	
	if (b==0)
	{
		return a;
	}
	else if (b==1)
	{
		return 1;
	}
	else
	{
		a=a-b;
		return simpleGCD(a,b);
		

	}
}

long findGCD(long l, long r)
{
	if(l<r)
	{
		if (dp[l][r]!= 0)
		{
			return dp[l][r];
		}
		else
		{
			dp[l][r]=simpleGCD( findGCD(l,r-1), a[r] ); 
			return dp[l][r];
		}
	}
	else if (l==r)
	{
		return a[l];
	}
}


int main()
{	cin>>n;
	for (long i = 1; i <= n; ++i)
	{
		cin>>a[i];
		if (a[i]==1)
		{
			cnt1++;
		}
	}
	if (cnt1>0)
	{
		cout<<n-cnt1;
	}
	else
	{	for (int i = 1; i <= n-1; ++i)
		{	for (int j = i+1; j <= n; ++j)
			{	if (findGCD(i,j)==1)
				{	flag=true;
					if(j-i < MIN)
					{	MIN= j-i;

					}	
				
				}
			
			}
		
		}

		if (flag==true)
		{
			cout<<MIN+(n-1);
		}
		else{
			cout<<"-1";
		}
		
	}

	return 0;
}