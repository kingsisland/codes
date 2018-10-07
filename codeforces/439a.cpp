#include <bits/stdc++.h>
using namespace std;
int main()
{	int n,d,sum=0;
	int t[101];
	cin>>n>>d;
	for (int i = 0; i < n; ++i)
	{
		cin>>t[i];
		sum+=t[i];

	}
	
	if (sum+(n-1)*10 <= d)
	{
		d=(d-sum)/5;
		cout<<d;
	}
	else
		cout<<"-1";



	return 0;
}
