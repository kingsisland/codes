#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int knapsack (int W,int val[],int wt[],int N)
{	int dp[N+1][W+1];

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{	if(i==0||j==0)
			{	dp[i][j]=0;
			}
			else
			{
				if(wt[i-1] <= j)
				{
					dp[i][j]=max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
				}
				else
				{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
	}

	return dp[N][W];


}




int main()
{	int n,W;
	cin>>n>>W;
	int val[n],wt[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>val[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>wt[i];
	}
	cout<<knapsack(W,val,wt,n);

	

	return 0;
}