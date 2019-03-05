#include <bits/stdc++.h>
#define N 1000005
using namespace std;


void calcF(string s, long F[])
{	
	F[0]=0;
	long n=s.length(),j;
	for (long  i = 1; i < n ; ++i)
	{	j=F[i-1];

		while(j>0 && s[j] != s[i])
		{
			j=F[j-1];
		}

		if(s[j] == s[i])
			++j;
			

		F[i]=j;
		
	}
}


long KMPSearch(string s, string pat)
{	
	long cnt=0;

	long i=0,j=0;

	long n=s.length(), m=pat.length();

	long lps[m+5];
	calcF(pat, lps);

	while( i < n )
	{	
		

		if(s[i]==pat[j])
		{
			i++;
			j++;
			
			
		}

		if(j == m)
		{	cnt++;
			j=lps[j-1];
		}

		else if(i<n && s[i] != pat[j])
		{	
			if(j != 0)
				j=lps[j-1];
			else
				i++;
		}
	}

	return cnt;

}


int main()
{	
	long F[N],n;
	string s;
	getline(cin,s);
	


	n=s.length();


	calcF(s,F);

	

	long cnt=0;

	long j=n;
	string pat;
		while(cnt < 3 && j>0)
	{	
		j=F[j-1];
		if(j>0)
		{
			pat= s.substr( 0,  j);
		
			
			cnt=KMPSearch(s, pat);
		}
	}

	if(j>0)
	{
		cout<<pat;	
	}
	else
		puts("Just a legend");


	


	return 0;
}
