#include <bits/stdc++.h>
using namespace std;
long long a[200005],sum[200005]={0},tsum=0,ans=0,cir,m=1000000005,no=0;
int main()
{
	long long n;
	unsigned long long t;
	cin>>n>>t;
	for (long long i = 1; i <=n; ++i)
	{	cin>>a[i];
		if(a[i]<m)
		{
			m=a[i];
		}
		tsum+=a[i];
		//sum[i]=tsum;
	}
	//sort(a,a+n);
	//cout<<endl<<tsum<<endl;

	
		// cir=t/tsum;
		// if(cir > 0)
		// {	ans+=cir*n;
		// 	t=t-(cir*tsum);
		// 	//cout<<cir<<" "<<t<<endl;
		// }
		long long i;
		while(t>=m )
		{	tsum=0;
			
			
			no=0;
			for ( i = 1; i <= n; ++i)
			{	if(tsum+a[i] <= t)
				{
					tsum+=a[i];
					no++;
				}
			}
			//cout<<t<<" "<<ans<<endl;
			//cout<<" "<<tsum<<" "<<no<<" "<<t/tsum<<endl;
			
			// if(t/tsum==0)
			// {	cout<<"\nin t/tsum==0\n";
			// 	t=t-tsum;
			// 	ans+=no;
			// }
			//else
				ans+=(no)*(t/tsum);
				t=t-(t/tsum)*tsum;
				
			
			//cout<<"\n ans: "<<ans<<" "<<endl;
			

		}
	
	cout<<ans;
}