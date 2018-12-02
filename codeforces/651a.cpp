#include <bits/stdc++.h>
using namespace std;
int a1,a2;
int dp[200][200]={0};
int charging(int i, int j)
{	if(i<0 || j<0)
	{
		return 0;
	}
	if(i==0 || j==0)
	{	
		return 1;
	}
	if(dp[i][j]!=0)
		return dp[i][j];

	dp[i][j]=1+max(charging(i+1, j-2), charging(i-2, j+1));
	return dp[i][j];

}
int main()
{	
	cin>>a1>>a2;
	cout<<charging(a1,a2)-1;
	return 0;
}