#include <bits/stdc++.h>
using namespace std;
//int count=0;

int findlength (int i,int super[],int count)
{	count++;
	//cout<<"\n i is : "<<i<<" count is :"<< count<<endl;
	if (super[i] == -1)
	{	//cout<<"\nReached the root-> i is : "<<i<<" count is :"<< count<<endl; 
		return count;
	}
	
	count=findlength(super[i], super, count);
	return count;
}
int main()
{	int n,max=-1,temp;
	cin>>n;
	int super [n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>super[i];
	}
	for (int i = 1; i <= n; ++i)
	{	//count=0;
		temp=findlength(i,super,0);
		if(temp>max)
		{
			max=temp;
		}

	}
	cout<<max;


	return 0;
}