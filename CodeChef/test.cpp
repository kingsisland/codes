#include <bits/stdc++.h>
using namespace std;
int main()
{	/*for (int i = 1; i <= 10; ++i)
	{
		for (int j = i+1; j <= 10; ++j)
		{
			for (int k = j+1; k <=10; ++k)
			{
				cout<<i<<"@"<<j<<"@"<<k<<":  "<<(i^j^k)<<endl;
			}
		}
	}*/



	/*for (int i = 1; i <= 1000; ++i)
	{
		
				cout<<i<<"@"<<i+1<<"@"<<i+2<<"   : "<<(i^(i+1)^(i+2))<<endl;
			
	}*/

	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			for (int k = j+1; k < n; ++k)
			{
				cout<<a[i]<<"@"<<a[j]<<"@"<<a[k]<<" : "<<(a[i]^a[j]^a[k])<<"\n";
			}
		}
	}

	return 0;
}