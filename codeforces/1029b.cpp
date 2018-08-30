#include <bits/stdc++.h>
using namespace std;
int main()
{ 
	long n,count=0;
	cin>>n;
	long a[n+1];
	multiset <long, greater <long> > maxlen; 
	for (long i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	// for (long i = 1; i < n; ++i)
	// {
	// 	/* code */
	// }
	long i=1;
	if(n>1)
	{
		while(i<=n-1)
		{
			if(a[i+1]<= a[i]*2)
			{	count++;
			}
			else
			{
				count++;
				maxlen.insert(count);
				count=0;
			}

			i++;
		}
		count++;
		maxlen.insert(count);
		multiset <long, greater <long> > :: iterator itr=maxlen.begin();
		cout<<*itr;
	}
	else
		cout<<"1";

	return  0;
}