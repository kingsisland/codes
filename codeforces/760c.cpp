#include <bits/stdc++.h>
#define INF 10e15
#define N 100005
using namespace std;
int n;
long long c[N],dp[N][2]={0},inf=INF;
string s[N],rs[N];




long long  findMin(){
	dp[0][0]=0;
	dp[0][1]=c[0];

	for (int i = 1; i <n ; ++i)
	{	dp[i][0] = INF;
		dp[i][1] = INF;
		
			if(s[i] >= s[i-1]){
				//cout<<"1\n";
				dp[i][0] = min(dp[i][0],dp[i-1][0]);
			}
			if(s[i] >= rs[i-1]){
				
				//cout<<"2 "<<s[i]<<"  "<<rs[i-1]<<endl;
				dp[i][0] = min(dp[i][0],dp[i-1][1]);
			}	

			if(rs[i] >= s[i-1]){
				//cout<<"3\n";
				dp[i][1] = min(dp[i][1],dp[i-1][0]+c[i]);
			}
			if(rs[i] >= rs[i-1]){
				//cout<<"4\n";
				dp[i][1] = min(dp[i][1],dp[i-1][1]+c[i]);
			}

			if(dp[i][0]==INF && dp[i][1] == INF)
				return INF;
		


	}

	long long ans=min(dp[n-1][0],dp[n-1][1]);
	return ans;
}








int main(){
	char t;
	int len,flag=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&c[i]);
	}

	
	
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
		
		rs[i].assign(s[i]);
		
		len=s[i].length();
		
		for (int j = 0; j < len /2 ; ++j)
		{	t=rs[i][j];
			rs[i][j]=rs[i][len-j-1];
			rs[i][len-j-1]=t;

		}
	
	}

		long long ans=findMin();
		if(ans == INF)
			cout<<"-1";
		else
			cout<<ans;
	


	return 0;
}