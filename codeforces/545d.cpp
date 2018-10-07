#include <bits/stdc++.h>
using namespace std;
int main()
{	long n,t[100005],count=0;
	long long sum=0;
	//set <long> t;
	
	cin>>n;
	for (long i = 0; i < n; ++i)
	{	cin>>t[i];
	}
	sort(t,t+n);
	for (long i = 0; i < n; ++i)
	{
		if (sum <= t[i])
		{
			count++;
			sum+=t[i];
		}
	}
	cout<<count;
	





	return 0;
}