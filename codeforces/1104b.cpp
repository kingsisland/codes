#include <bits/stdc++.h>
using namespace std;
int main()
{	string s;
	cin>>s;
	int i,j,n,cnt=0;
	n=s.length();
	int prev[n+1];

	prev[0]=-1;
	i=0;
	j=1;
	while(i!= j && j<n){
		//cout<<"\n i: "<<i<<" j : "<<j;
		if(s[i] == s[j]) 
		{	//cout<<"\nmatch\n";
			s[i] = '.';
			s[j] = '.';
				cnt++;

				if(i>0)
				{
					prev[i]=prev[i-1];
					
				}
				prev[j]=prev[i];
				
				if(prev[i] == -1 )
				{	
					i=j+1;
					j+j+2;
				}
				else
				{	//cout<<"\nhere\n";
					i=prev[i];
					j=j+1;
				}
		}
		else if(s[i] != s[j])
		{	prev[i]=i;
			prev[j]=j;

			i=j;
			j=j+1;

		}

	}
	if(cnt%2==0)
		puts("No");
	else
		puts("Yes");
	






	return 0;
}