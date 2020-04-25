#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
      // int abs_val(int n)
      // {
      //       int val = (n >= 0)?n:-n;
      //       return val;
      // }

	bool isUgly(int n) {
            if(n <= 0) return false;
            long num = n;
            while(abs(num) > 1)
            {     //cout<<"num : "<<num<<endl;
                  if(num%2 == 0) num/=2;
                  else if(num%3 == 0) num/= 3;
                  else if(num%5 == 0) num/= 5;
                  else
                        return false;
                  
            }
            return true;

    }
};


int main()
{	
	Solution solution = Solution();
	int n;
	cin>>n;
	cout<<solution.isUgly(n);
	
	return 0;
}