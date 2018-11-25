#include <bits/stdc++.h>
using  namespace std;
long long freq[100005]={0};
long long max(long long a, long long b)
{
	if(a>=b)
		return a;
	else
		return b;
}
long long findMax(long long n)
{
	long long dp[n+1];
	dp[0]=0;
	dp[1]=freq[1];
	for (long long i = 2; i <= n; ++i)
	{
		dp[i]=max(dp[i-2]+freq[i]*i, dp[i-1]);
	}
	return dp[n];
}
int main(){
	long long  n,m=0,a;
	cin>>n; 
	for (long long i = 0; i < n; ++i)
	{
		cin>>a;
		freq[a]++;
		if(a>m)
			m=a;

		
	}
	cout<<findMax(m);




	return 0;
}