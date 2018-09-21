#include <bits/stdc++.h>
using  namespace std;
void print_step (string str, int steps)
{
	for (int i = 0; i < steps; ++i)
	{
		cout<<str<<"\n";
	}
	return;
}
int main()
{	string s,e;
	cin>>s>>e;
	int horizontal = e[0]-s[0];
	int vertical = e[1]-s[1];
	int absWidth= abs(horizontal);
	int absHeight = abs(vertical);
	//cout<<"\n absWidth is: "<<absWidth<<"  absHeight is: "<<absHeight<<endl;
	int minimum = min(absHeight, absWidth);
	int maximum = max(absHeight, absWidth);
	cout<<maximum<<"\n";
	//cout<<minimum<<endl;
	if(minimum == absWidth)
	{	if(vertical < 0)
		{
			if(horizontal < 0)
			{
				print_step("LD",minimum);
				
			}
			if(horizontal>=0)
			{
				print_step("RD",minimum);
			}
			print_step("D",maximum-minimum);
		}
		if(vertical >= 0)
		{	
			if(horizontal < 0)
			{
				print_step("LU",minimum);
				
			}
			if(horizontal>=0)
			{	//cout<<"\nin here\n";
				print_step("RU",minimum);
			}
			print_step("U",maximum-minimum);

		}

	}
	else if(minimum == absHeight)
	{
		if(horizontal < 0)
		{
			if(vertical < 0)
			{
				print_step("LD",minimum);
			}
			if(vertical >= 0)
			{
				print_step("LU",minimum);
			}
			print_step("L",maximum-minimum);

		}
		if(horizontal >= 0)
		{
			if(vertical < 0)
			{
				print_step("RD",minimum);
			}
			if(vertical >= 0)
			{	//cout<<"\nin here\n";
				print_step("RU",minimum);
			}
			print_step("R",maximum-minimum);
		}
	}
	
	return 0;
}