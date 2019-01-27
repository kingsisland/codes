#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,flag=0;
	int res[10]={0};
	cin>>n;
	if(n%2==0)
	{
		cout<<n/2<<"\n";
		for (int i = 0; i < n/2; ++i)
		{
			cout<<"2 ";
		}

	}
	else{
		for (int i = 3; i < 10; ++i)
		{
			if(n%i==0)
			{	
				flag=1;
				cout<<n/i<<"\n";
				for (int j = 0; j < n/i; ++j)
				{
					cout<<i<<" ";
				}
				break;

			}
		}
		if(flag==0){
			cout<<n<<"\n";
			for (int i = 0; i < n; ++i)
			{
				cout<<1<<" ";
			}
			
		}
	}




	return 0;
}