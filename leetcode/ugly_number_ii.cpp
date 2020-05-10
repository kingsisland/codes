#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

	int nthUglyNumber(int n) {
       int p2=0, p3 =0, p5=0;
       int* numbers = new int[n];
       numbers[0] = 1;
       for(int i =1; i<n; i++)
       {
            int val_p2 = numbers[p2]*2;
            int val_p3 = numbers[p3]*3;
            int val_p5 = numbers[p5]*5;

<<<<<<< HEAD
            //cout<<"val_p2 : "<<val_p2<<" val_p3 : "<<val_p3<<" val_p5: "<<val_p5<<endl;
=======
            cout<<"val_p2 : "<<val_p2<<" val_p3 : "<<val_p3<<" val_p5: "<<val_p5<<endl;
>>>>>>> abc22c83539a7e1fb6ad00dcef25b2ea31b69828

            int min_val = min(val_p2, min(val_p3, val_p5));
            numbers[i] = min_val;
            if(min_val == val_p2) p2++;
            if(min_val == val_p3) p3++;
            if(min_val == val_p5) p5++;
       }
       return numbers[n-1];
    }
};
int main()
{	
	Solution solution = Solution();
	int n;
	cin>>n;
	cout<<solution.nthUglyNumber(n);
	
	return 0;
}