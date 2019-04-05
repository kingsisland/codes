#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,cnt=0;
	bool res[5];
	memset(res,false,5*sizeof(bool));
	cin>>n;
	string s;
	cin>>s;
	for(int i=0; i< s.length(); i++)
	{	if(cnt >= 4)
		{
			cout<<"Yes";
			break;
		}
		else if(s[i] == 'a' && res[0]==false)
		{		res[0]=true;
				cnt++;
		}
		else if(s[i] == 'e' && res[1]==false)
		{
				res[1]=true;
				cnt++;
		}
		else if(s[i] == 'i' && res[2]==false)
		{
				res[2]=true;
				cnt++;
		}
		else if(s[i] == 'o' && res[3]==false)
		{
				res[3]=true;
				cnt++;
		}
		else if(s[i] == 'u' && res[4]==false)
		{
				res[4]=true;
				cnt++;
		}
	}

	if(cnt < 4)
		cout<<"No";

	return 0;
}