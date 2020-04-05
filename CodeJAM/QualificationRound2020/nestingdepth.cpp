#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int test_case=1; test_case <= t; test_case++)
	{	
		string s,ans;
		cin>>s;
		int level =0,digit;

		for(int i=0; i < s.length(); i++)
		{
			digit = s[i] - '0';
			if(level < digit)
			{
				while(level < digit)
				{
					ans+="(";
					level++;
				}
			}
			else if( level > digit){
				while(level > digit)
				{
					ans+=")";
					level--;
				}
			}
			ans.push_back(s[i]);
		}

		while(level != 0)
		{
			ans+=")";
			level--;
		}

		cout<<"Case #"<<test_case<<": "<<ans<<"\n";


	}
	return 0;

}