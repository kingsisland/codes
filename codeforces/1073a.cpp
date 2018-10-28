#include <bits/stdc++.h>
using namespace std;
int main()
{	int n;
	cin>>n;
	string s;
	cin>>s;
	int j;
	int flag;
	for (int i = 0; i < n; ++i)
	{	int freq[26]={0};
		flag=0;
		for(j=i;j<n;j++)
		{	
			freq[s[j]-97]+=1;
			

		}
		
		for (int k = 0; k < 26; ++k)
		{	
			if(freq[k] > (j-i)/2)
			{
				flag=1;
				break;
			}

		}
		
		if(flag==0)
		{	cout<<"YES\n";
			for (int k = i; k < j; ++k)
			{	
				cout<<s[k];
				
		
			}
			cout<<endl;
			flag=2;
			

		}
		if(flag==2)
		{	//cout<<"\n breking";
			break;
		}
	}
	if(flag!=2)
	{
		cout<<"NO";
	}


	return 0;
}
