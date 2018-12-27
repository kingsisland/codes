#include <bits/stdc++.h>
using namespace std;
//long long c;
long spf[5000005];
long  dp[5000005];
long freq[5000005]={0};
void seive()
{
	spf[1] = 1;

	for (long i = 2; i <= 5000005; ++i)
		spf[i]=i;
	
	for (long i = 2; i <=5000005; i+=2)
		spf[i] = 2;
	

	for (long i = 3; i*i<= 5000005 ; ++i)
	{	if (spf[i] == i)
		{	

			for (long j = i*i; j <= 5000005 ; j=j+i)
			{
				if (spf[j]==j)
				{
					spf[j] = i;
				}
			}
		
		}
		
	}
	return;
}

void  score()
{	
	/*//cout<<"n: "<<n<<endl;
	if(dp[n] != -1)
	{
		return dp[n];
	}
	else
	{	//cout<<"spf is: "<<spf[n]<<endl;
		dp[n] = 1 + score(n/spf[n]);
		
		return dp[n];
	}*/
	dp[1] = 0;

	for (long i = 2; i <= 5000000 ; ++i)
	{
		if(spf[i]== i)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i]= 1 + dp[i/spf[i]];
		}
	}
	

	freq[1] = 0;
	
	//maintaining the freq array
	for (long i = 2; i <= 5000000 ; ++i)
	{
		freq[i]=dp[i]+freq[i-1];


	}

	return;
}






int main()
{	

	long t,a,b;
	seive();
	
	//dp[1] = 0;
	score();


	cin>>t;
	while(t--)
	{	//c=0;
		//cin>>a>>b;
		scanf("%ld %ld",&a,&b);
		if(a>b)
		{	//cout<<freq[a]-freq[b]<<"\n";
		printf("%ld\n",freq[a]-freq[b] );

		}
		else
		{
			printf("0\n");
		}

	}

	

	return 0;
}