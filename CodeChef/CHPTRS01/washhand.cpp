#include <bits/stdc++.h>
using namespace std;
void displayVector(int vec[], int n)
{
	cout<<endl;
	for(int i =1; i <= n; i++)
		cout<<vec[i]<<"  ";
	cout<<endl;
}

int main()
{	
	int t,n,d;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int totCount=0;

		int infected[n+1];
		bool isBan[n+1];
		fill(isBan, isBan+n+1, false);

		stack<int> onesList;

		string s;
		cin>>s;
		for(int i=1; i<=n; i++)
		{
			infected[i] = s[i-1]-'0';
			if(infected[i]==1) {
				onesList.push(i);
				totCount++;
			}
		}


		cin>>d;

		int isol[d+1];
		for(int i =1; i<=d; i++)
			cin>>isol[i];

	           
		for(int day=1; day<= d; day++)
		{
			isBan[ isol[day]] = true;

			stack<int> newOnes;

			int idx;
			while(!onesList.empty())
			{	
				idx = onesList.top();
				onesList.pop();

				if(idx-1>0 && !isBan[idx] && infected[idx-1]==0){
					totCount++;
					infected[idx-1] = 1;
					newOnes.push(idx-1);
				}

				if(idx+1 <= n && !isBan[idx+1] && infected[idx+1]== 0){
					totCount++;
					infected[idx+1] = 1;
					newOnes.push(idx+1);
				}
			}

			onesList = newOnes;
		}

		cout<<totCount<<"\n";
	}

	return 0;
}