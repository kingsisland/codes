#include <bits/stdc++.h>
using namespace std;
long s[100005];
int main()
{	int t;
	cin>>t;
	long n,k,temp,count;
	while(t--)
	{	count=0;
		cin>>n>>k;
		for (long i = 0; i < n; ++i)
		{
			cin>>s[i];
		}
		sort(s,s+n,greater<long>());
		
		temp=s[k-1];
		for (long i = k; i < n; ++i)
		{
			if (s[i]<temp)
			{
				break;
			}
			else
			{
				count++;
			}
		}
		count+=k;
		cout<<count<<"\n";


	}




	return 0;
}