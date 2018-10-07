#include <bits/stdc++.h>
using namespace std;
int main()
{	long n,digits=0,c14=0,c144=0,flag=0;
	int c[10];
	cin>>n;
	stack <int> s;
	while(n>0)
	{
		s.push(n%10);
		n=n/10;
	}
	while(!s.empty())
	{	c[digits]=s.top();
		s.pop();
		digits++;

	}	
	
	for (int i = 0; i < digits; ++i)
	{
		if (c[i]==1)
		{	c144=0;
			c14=0;

		}
		else if(i>0 && (c[i-1]==1|| c[i-1]==4) && c[i]==4)
		{
			if (c14==0 & c144==0)
			{
				c144+=1;
				c14+=1;
			}
			else if(c144==1)
			{
				c144+=1;
				c14=0;
			}
			else
			{	cout<<"NO";
				flag=1;
				break;

			}
		}
		else
		{
			cout<<"NO";
			flag=1;
				break;
		}
	}
	if (flag==0)
	{
		cout<<"YES";
	}





	return 0;
}