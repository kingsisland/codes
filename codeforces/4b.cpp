#include <bits/stdc++.h>
using  namespace std;
int Min[31],freqMin[31],Max[31],freqMax[31];
int d,sumTotal;

int ans[31];
void printAns()
{
	for (int i = 1; i <=d ; ++i)
	{
		cout<<ans[i]<<" ";
	}
	return;
}
int possible(int day,int sum)
{
	if(freqMin[d]-freqMin[day]+Min[day]> sum)
		return 0;

	if(freqMax[d]-freqMax[day]+Max[day] < sum)
		return 0;

	return 1;
}
int findStudy(int day,int sum)
{
	if(day==d+1)
	{
		if(sum==0)
		{
			cout<<"YES\n";
			printAns();
			return 1;
		}
		else
		{
			//cout<<"NO";
			return 0;
		}

	}
	for (int i = Min[day]; i <= Max[day]; ++i)
	{
		if(possible(day,sum))
		{
			ans[day]=i;
			if(findStudy(day+1,sum-i))
			{	return 1;
			}
		}
	}
	return 0;
}
int main()
{	freqMin[0]=0;
	freqMax[0]=0;
	cin>>d>>sumTotal;
	for (int i = 1; i <=d; ++i)
	{
		cin>>Min[i]>>Max[i];

		freqMin[i]=freqMin[i-1]+Min[i];
		freqMax[i]=freqMax[i-1]+Max[i];
	}
	if (!findStudy(1,sumTotal))
	{
		cout<<"NO";
	}


	return 0;
}