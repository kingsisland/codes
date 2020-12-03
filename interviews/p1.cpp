#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
//Space Complexity: O(1) excluding the space for string s
int main()
{
	int n;
	cin>>n;
	string s;
	int ans =0;
	cin>>s;
	int count = 0;
	for(int i =0; i<n; i++)
	{
		if(s[i] != 'x')
		{
			if(count >=3)
			{
				ans += count -2;
			}
			count =0;
		}
		else
			count++;
	}
	if(count > 3)
	{
		ans += count -2;
	}
	count =0;
	cout<<ans;
}