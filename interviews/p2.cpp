#include<bits/stdc++.h>
using namespace std;

// Time complexity O(1)
int main()
{
	int t;
	cin>>t;

	int n;
	while(t--)
	{
		cin>>n;
		int a = (n-1)*n;
		a /= 2;

		a += 1;
		cout<<n*a + (n*(n-1))/2<<endl;
	}
	return 0;
}