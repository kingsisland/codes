#include <bits/stdc++.h>
using namespace std;
bool divEight3 (int a[],int len)
{	int val=0;
	for (int i = 0; i <= len-3; ++i)
	{	val=0;
		val+=a[i]*100;
		for (int j = i+1; j <= len-2; ++j)
		{	val+=a[j]*10;
			for (int k = j+1; k <=len-1; ++k)
			{	val+=a[k];
				if(val%8==0)
				{
					cout<<"YES\n";
					if(a[i]!=0)
					{
						cout<<a[i];

					}
					if(a[j]!=0)
					{
						cout<<a[j];
					}
					cout<<a[k];
					return true;
				}
				val-=a[k];
				
			}
			val-=a[j]*10;
		}
	
	}

	//cout<<"NO\n";
	return false;
	

}

bool divEight2 (int a[],int len)
{	
	int val=0;
	for (int i = 0; i <= len-2; ++i)
	{	val=0;
		
		val+=a[i]*10;
		
		for (int j = i+1; j <=len-1; ++j)
		{	val+=a[j];
			if (val%8==0)
			{	cout<<"YES\n";
				if (a[i]!=0)
				{
					cout<<a[i];
				}
				cout<<a[j];
				return true;
			}
			val-=a[j];
		}
		val-=a[i]*10;
	}
	return false;
}
int main()
{
	string s;
	cin>>s;
	int len=s.length(),flag=0;
	int a[len];
	for (int i = 0; i < len; ++i)
	{
		a[i]=s[i]-48;
		if((a[i]==0 || a[i]==8 ) && flag==0 )  //single digit check
		{
			flag=1;
			cout<<"YES\n"<<a[i];
		}
	
	}
	if(flag==0)
	{
		bool three=divEight3(a,len);
		if(three==false)
		{	
			bool two=divEight2(a,len);
			if (two==false)
			{
				cout<<"NO\n";
			}
		}
	}
	





	return 0;
}