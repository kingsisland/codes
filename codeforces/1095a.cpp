#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,index=-1;
	cin>>n;
	char a[n+1];
	cin>>a;
	for (int i = 1; i < n; i++)
	{	index=index+i;
		if(index<n)
		{	cout<<a[index];

		}
		else
		{
			break;
		}
		
	}
	if (n==1)
	{
		cout<<a;
	}

}