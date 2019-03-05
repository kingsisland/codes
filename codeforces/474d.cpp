#include <bits/stdc++.h>
using namespace std;
int visited[100005]={0};
long dp[100005]={0},k;
long a[100005],b[100005];

long find(long i) {
	if(i<0) {return 0;}
	if(visited[i]==1){ return dp[i]; }
	else{
		visited[i]=1; //mark visited
		dp[i]=find(i-1)+find(i-k);
		
			dp[i]=dp[i]%1000000007;
		
		
		return dp[i];
	}
}





int main(){
	
    


	long t,MAX=0,l,r;
	cin>>t>>k;
	

	

	
	visited[0]=1;
	visited[1]=1;

	dp[0]=1;
	
	if(k==1) { dp[1]=2; }
	else { dp[1]=1; }

	

	for (long i = 1; i <= t; ++i)
	{
		

		scanf("%ld %ld",&a[i],&b[i]);
		
	

		if (b[i] > MAX) {	MAX = b[i]; }
	}

	find(MAX);
	
	long prefSum[100005]={0};
	//prefSum[1]=dp[1];

	for (long i = 1; i < MAX+1; ++i)
	{
		prefSum[i]=(prefSum[i-1] + dp[i])%1000000007;
	}



	for (long i = 1; i <= t ; ++i)
	{	

		l=a[i];
		r=b[i];

		 long count = (prefSum[r] - prefSum[l-1] + 1000000007 )%1000000007;

		
		 

		//cout<<count<<"\n";
		printf("%ld\n",count );
		
	}




	return 0;
}