#include <iostream>
using namespace std;
int main()
{	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	long long m,n,rem,base;

	cin>>t;
	while(t--)
	{	cin>>m>>n;
		base=m/n;
		rem=m%n;
		for (int i = 1; i <= n-rem; ++i)
		{
			cout<<base<<" ";
		}
		for (int i = n-rem+1; i <= n; ++i)
		{
			cout<<base+1<<" ";
		}
		cout<<"\n";

	}
	
	return 0;
}