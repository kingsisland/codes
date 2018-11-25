#include <bits/stdc++.h>
using namespace std;
int freq[105]={0};
int main()
{	int n,stop,line;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{	cin>>stop;
		while(stop--)
		{	cin>>line;
			freq[line]++;

		}
		
	}

	for (int i = 1; i <= 100; ++i)
	{
		if (freq[i]==n)
		{
			cout<<i<<" ";
		}
	}

	return 0;
}