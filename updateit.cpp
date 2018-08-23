#include <bits/stdc++.h>
using namespace std;
long n;
void Update (long long ft[],long i,long long val)
{	
	//cout<<"\n Updating idx i: "<<i<<" with value : "<<val<<endl;
	while( i<=n)
	{	//cout<<"\n i is : "<<i<<endl;
		ft[i]+=val;
		//cout<<"\n ft[i] is "<<ft[i]<<endl;
		i += i & (-i);
		//cout<<"\n updated i is : "<<i<<endl;
	}
	//cout<<"I'm out side the for loop \n";
	return ;

}

long long Query (long long ft[],long i)
{	//cout<<"\n ENtered the query function :\n";
	long long sum=0;
	// for( ;q>0;q -= q & (-q))
	// {
	// 	sum+=ft[q];
	// }
	while( i>0)
	{//	cout<<"\n i is : "<<i<<endl;
		sum+=ft[i];
		//cout<<"\n ft[i] is "<<ft[i]<<endl;
		i -= i & (-i);
		//cout<<"\n updated i is : "<<i<<endl;
	}
	//cout<<"I'm out side the for loop \n";
	return sum;

}
int main()
{	//for faster input 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	int t;
	cin>>t;
	long u,l,r,q,ask;
	long long val;
	while(t--)
	{	cin>>n>>u;
		long long ft[n+1]={0};
		 // long long *ft = new long long[n+1];
   //  	for (long i=0; i<=n; i++)
   //      ft[i] = 0;
		for(long i=u;i>0;--i)
		{	cin>>l>>r>>val;
			Update(ft,l+1,val);
			Update(ft,r+2,-val);

			//cout<<"\n Update completed and U is : "<<i<<"\n";

		}
		//displaying the FT
		// cout<<endl;
		// for (long i = 0; i < n; ++i)
		// {
		// 	cout<<ft[i]<<"  ";
		// }
		// cout<<endl;

		//cout<<"\n entering queries : \n";

		cin>>q;
		while(q--)
		{	//cout<<"\n enter the query index : ";
			cin>>ask;
			val=Query(ft,ask+1);
			cout<<val<<"\n";
			
		}

	}
	return 0;
}