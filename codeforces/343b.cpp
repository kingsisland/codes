#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int prev[100005],n=s.length(),x,y,count=0;
	prev[0]=-1;

	x=0;
	y=1;
	while(y<n) {
		if(s[x] == s[y])
		{
			s[x]='.';
			s[y]='.';

			count+=2;

			prev[y]=prev[x];

			if(prev[x] != -1)
			{	
				x=prev[x];
				y=y+1;
			}
			else
			{
				x=y+1;
				y=y+2;
			}
		}
		else if(s[x] != s[y])
		{
			prev[y]=x;
			x=y;
			y=y+1;
		}
	}
	if(count==n)
		puts("Yes");
	else
		puts("No"); 


	return 0;
}