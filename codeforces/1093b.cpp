#include <bits/stdc++.h>
using namespace std;
int freq[30];
int isPalindrome(string s) 
{ 
    // Start from leftmost and rightmost corners of s 
    int l = 0; 
    int h = s.length() - 1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (s[l++] != s[h--]) 
        { 
            //not a palindrome
            return 0; 
        } 
    } 
    return 1;
} 
int main()
{	int t,len,flag;
	char c;
	string s;
	cin>>t;
	while(t--)
	{	cin>>s;
		if(!isPalindrome(s))  //not a plaindrome
		{	cout<<s<<"\n";
		}
		else	//is a palindrome
		{	len=s.length();
			for (int i = 0; i < 30; ++i)  //reset the freq array
			{	freq[i]=0;
			}

			for (int i = 0; i < len; ++i)
			{
				freq[s[i]-97]++;
			}
			flag=0;
			for (int i = 0; i < 26; ++i)
			{
				if(freq[i] == len)
				{	cout<<"-1\n";
					flag=1;
					break;

				}
			}

			if(flag==0)
			{
				for (int i = 0; i < 26; ++i)
				{	c=char(i+97);
					for (int j = 0; j < freq[i]; ++j)
					{	printf("%c",c );
						
					}

				}
				printf("\n");
			}




		}


	}




	return 0;
}