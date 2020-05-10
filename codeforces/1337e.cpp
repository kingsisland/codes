#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
unordered_map<string, int> dp;

int useDP(string A, int index, string S, string T)
{	cout<<"A : "<<A<<endl;
	if(dp.find(A) != dp.end())
	{
		cout<<"dp Already found\n\n";
		return dp[A];
	}
	if(A.length() == S.length())
	{
		if(A.substr(0, T.length()) == T)
		{
			dp[A] = 1;
			cout<<"found\n\n";
			return 1;
		}
		dp[A] = 0;
		return 0;
	}

	string SA = A, AS =A;
	SA.insert(SA.begin(), S[index]);
	AS.push_back(S[index]);
	dp[A] = (useDP( SA, index+1, S, T) % MOD + 
				  	useDP(AS , index+1, S, T) % MOD) % MOD;
	
	if(A.length() >= T.length() && A.substr(0, T.length()) == T)
		dp[A] = (dp[A] + 1)%MOD;

	cout<<"Dp calculated now\n\n";
	return dp[A];
}



int main()
{
	// string S, T;
	// cin>>S>>T;
	// cout<<useDP("", 0, S, T);
	int a =2,A[1];
	if(a || A[11] == 1 )
		cout<<true;
}