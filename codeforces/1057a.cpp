#include <bits/stdc++.h>
using namespace std;
int main()
{	long n;
	cin>>n;
	long a[n+1];
	for (int i = 2; i <= n; ++i)
	{
		cin>>a[i];
	}
	stack <long> s;
	long temp=n;
	s.push(temp);
	while(temp!=1)
	{	temp=a[s.top()];
		s.push(temp);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}




	return 0;
}