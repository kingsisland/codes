#include <bits/stdc++.h>
using namespace std;


void updateBIT(long long  BITree[], long n, long index, long long val)
{
    // index in BITree[] is 1 more than the index in arr[]
   // index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;
 
       // Update index to that of parent in update View
       index += index & (-index);
    }
}

long long bitQuery (long long ft[],long q)
{	long long sum=0;
	for( ;q>=0;q -= q & (-q))
	{
		sum+=ft[q];
	}
	return sum;

}
int main()
{	//for faster input 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    cout<<"START";

	int t;
	cin>>t;
	long n,u,l,r,q,ask;
	long long val;
	while(t--)
	{	cout<<"\nEnter n and u :\n";
		cin>>n;
		cin>>u;
		long long ft[n+1]={0};

		for(long i=u;i>0;--i)
		{	cout<<"\n enter l and val\n";
			cin>>l;
			cin>>val;
			updateBIT(ft, n,l,val);
			//Update(ft,r+2,-val);

			cout<<"\n Update completed and U is : "<<i<<"\n";

		}
		//displaying the FT
		// cout<<endl;
		// for (long i = 0; i < n; ++i)
		// {
		// 	cout<<ft[i]<<"  ";
		// }
		// cout<<endl;

		cout<<"\n entering queries : \n";

		cin>>q;
		while(q--)
		{	cin>>ask;
			cout<<bitQuery(ft,ask)<<"\n";
			
		}

	}
	return 0;
}