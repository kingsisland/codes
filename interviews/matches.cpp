
#include <bits/stdc++.h>
using namespace std;
unordered_map<long, long> dp;
long get_mask(long u)
{
	long ans =0;
	while(u){
		long rem = u%10;
		ans  |= (1<<rem);
		u /= 10;
	}

	return ans;
}

long dp_Fill(long val, long a[], long n)
{
	if(val == 0) 
		return 0;
	if(dp.find(val) != dp.end())
		return dp[val];
	long temp=0;
	for (long i =0; i<n; i++){
		long mask = get_mask(a[i]);

		if((mask | val) == val) {
			long t = dp[val^mask];
			dp[val] = max(max((long)0, t) 
				+ a[i], dp[val]);
		}
	}

	return dp[val];

}
long findAns(long a[], long n)
{
	long ans =0 ;
	for(int i =0; i < (1<<10); i++)
	{
		ans = max(ans, dp_Fill(i, a, n) );
	}

	return ans;
}
int main()
{
	long t;
	cin>>t;
	long n;
	long a[150];
	while(t--)
	{	
		dp.clear();
		cin>>n;
		for(int i=0; i < n; i++)
			cin>>a[i];
		cout<<findAns(a, n)<<"\n";

	}
}