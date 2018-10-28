#include <bits/stdc++.h>
using namespace std;
long long p[5005];
long long sum[5005]={0},pairs[5005]={0},tsum=0;
bool dp[5005];
int n;
long long  findMax(int i,int  m,int k)
{	long long ans=0,ansl,ansr;
	//cout<<" i: "<<i<<" k: "<<k<<endl;
	if(/*i+m-1 >= m &&*/ k>0 && i+m-1<=n && n-i+1 >= m*k) 
	{	
		if(dp[i]==false)
		{	pairs[i]=sum[i+m-1]-sum[i]+p[i];
			dp[i]=true;
		}
		//ans=max(pairs[i]+findMax(i+m,m,k-1), findMax(i+1,m,k));
		ansl=pairs[i]+findMax(i+m,m,k-1);
		ansr= findMax(i+1,m,k);
		ans=max(ansl,ansr);
		//cout<<"\ni: "<<i<<" pairs[i]: "<<pairs[i]<<" ansl: "<<ansl<<" ansr: "<<ansr<<" ans: "<<ans<<endl;
		return ans;
	}
	else 
	{	//cout<<" here k==0 and i: "<<i<<endl;
		return 0;
	}

}




int main()
{	int m,k;
	cin>>n>>m>>k;
	for (int i = 1; i <= n; ++i)
	{
		cin>>p[i];
		tsum+=p[i];
		sum[i]=tsum;
		dp[i]=false;
	}
	if(k==1 && m==1)
	{
		sort(p,p+n+1,greater<long long>());
		cout<<p[0];
	}
	else
	cout<<findMax(1,m,k);
	





	return 0;
}
