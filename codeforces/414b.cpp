#include <bits/stdc++.h>
#define MOD 1000000007
#define N 2005
using namespace std;

long dp[N][N]={0},cnt=0;
//bool visited[N][N]={false};
long n,k;

void maxWays(long place)
{	
	if( place > k)
		return;
	/*if(visited[number][place]==true)
		cnt= ( cnt + dp[number][place] )%MOD;*/


	
	/*else
	visited[number][place]=true;*/

	long number=1;
	while(number <= n)
	{
		long ways=0;
		for (long i = 1; i*number <= n; i++)
		{
			ways=(ways + dp[i*number][place-1] ) % MOD;
		}
	

		dp[number][place] = ways;
		/*cnt= ( cnt + dp[number][place] )%MOD;*/

		number++;
	}

	maxWays(place+1);
	
}




int main()
{
	
	cin>>n>>k;

	/*if(n==1 && k==1)
	{
		cout<<"0\n";
		exit(0);
	}*/
	//ground task
	for(long i=1;i<=n;i++)
	{
		//visited[i][1]=true;
		dp[i][1] = 1;
	}
	
	maxWays(2); //start from second place 

	for (long  i = 1; i <= n ; ++i)
	{
		cnt = ( cnt + dp[i][k]) % MOD;
	}
	cout<<cnt<<"\n";


}
