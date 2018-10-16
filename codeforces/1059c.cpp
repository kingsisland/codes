#include <bits/stdc++.h>
using namespace std;
void Cal(long n,long mul)
{	//cout<<"\n n: "<<n<<" and mul: "<<mul<<endl;
	if (n==1)
	{
		cout<<mul<<" ";
		return;
	}
	if (n==2)
	{
		cout<<mul<<" "<<mul*2<<" ";
		return;
	}
	if (n==3)
	{
		cout<<mul<<" "<<mul<<" "<<mul*3<<" ";
		return;
	}
	for (long i = 1; i <= n; ++i)     //takes care of odd numbers
	{
		if(i%2==1)
		{
			cout<<mul<<" ";
		}
	}
	//cout<<"\n n: "<<n<<" and mul: "<<mul<<endl;
	Cal(n/2,mul*2);
}




int main()
{
	long n,temp;
	cin>>n;
	Cal(n,1);


	return 0;
}