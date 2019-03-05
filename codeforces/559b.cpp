#include <bits/stdc++.h>
using namespace std;
string a,b;

string Shorten(string s)
{	long n=s.length();
	if( n % 2 != 0 )
		return s;

	string a= Shorten(s.substr(0,n/2));
	string b= Shorten(s.substr(n/2, n/2 ));

	if(a<b)
		return a+b;
	else
		return b+a;
}


int main()
{	string a,b;
	getline(cin,a);
	getline(cin,b);

	if(Shorten(a)==Shorten(b))
		puts("YES");
	else
		puts("NO");

	return 0;
}