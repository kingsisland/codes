#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int, int> pairs;

vector<int> converToBinary(long long n)
{
	vector<int> binary;
	while(n != 0)
	{
		binary.pb(n%2);
		n /=2;
	}

	reverse(binary.begin(), binary.end());
	return binary;
}

void displayVector(vector<int>& vec)
{
	cout<<endl;
	for(int i =0; i < vec.size(); i++)
		cout<<vec[i]<<"  ";
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	long long a,b;

	while(t--)
	{	cin>>a>>b;
		vector<int> A = converToBinary(a), B = converToBinary(b);
		if(A.size() < B.size())
		{
			while(A.size() < B.size())
			{
				A.insert(A.begin(),0);
			}
		}
		else if(A.size() > B.size())
		{
			while(A.size() > B.size())
			{
				B.insert(B.begin(), 0);
			}
		}
		// displayVector(A);
		// displayVector(B);

		long long maxVal=0;
		int rot;

		for(int rotation=0; rotation < B.size(); rotation++)
		{	long long sum=0; int p=0;
			for(int i=A.size()-1; i > -1; i--)
			{
				if(A[i] != B[i]) sum = sum+ (long long)pow(2, A.size()-1 - i);
			}


			if(maxVal <  sum) {
				maxVal = sum;
				rot = rotation;
			}

		
			
			B.insert(B.begin(), B.back());
			B.pop_back();

		}
		cout<<rot<<" "<<maxVal<<"\n";


	}
	return 0;
}