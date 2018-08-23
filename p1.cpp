#include<bits/stdc++.h>
using namespace std;
int main()
  {	    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;
	 long long n,sum,root;
	 long long i;
	while(t--)
	{	sum=1;i=2;
		cin>>n;
		//root=sqrt(n);
		//cout<<"\n sqrt of "<<n<<" is :"<<root<<endl;

		while(i<=sqrt(n))
		{	if (n%i==0)
			{	//cout<<" i is : "<< i << " n/i is : "<<n/i<<endl;
				// sum=sum+i;
				// sum=sum+(n/i);
				//cout<<sum<<endl;
			if (i==(n/i))
				{
					sum=sum+i;
				}
				else{
					sum=sum+i+(n/i);
				

				}

			}
			i++;
			//cout<<sum<<endl;

		}
		// if (n%i==0)
		// {	//cout<<" i is : "<< i << " n/i is : "<<n/i<<endl;
		// 	// sum+=i;
		// 	if(i==(n/i)){
		// 		sum+=i;
		// 	}
		// 	else{
		// 		sum=sum+i;
		// 		sum=sum+(n/i);
		// 	}
		// }
		cout<<sum<<"\n";


	}
	return 0;
}