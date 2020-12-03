#include <bits/stdc++.h>
using namespace std;

int Min_num (int K)	{
	int count =0;
	int num = 0;
	while(count < K)
	{	
		num++;
		int factors = 0;
		for(int i = 1; i <= sqrt(num); i++)
		{
			if(num%i == 0)
			{	
				int j = num/i;
				if(i == j)
					factors += 1;
				else
					factors += 2;
			}
		}
		count += factors;
	}
	return num;
}

int main()
{
	int K;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>K;
		cout<<Min_num(K)<<endl;
	}
}