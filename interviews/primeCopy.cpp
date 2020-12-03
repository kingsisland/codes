#include <bits/stdc++.h>
using namespace std;

vector<bool> primes(180, true);
unordered_map<int, int> dS;
vector<int> ans;

int isPrime(int i)
{
	int num = i;
	int digitSum = 0;
	if(dS.find(num) != dS.end())
		digitSum= dS[num];
	else{
		while(num > 0){
			digitSum += num%10;
			num/= 10;
		}
		dS[i] = digitSum;
	}

	if(primes[digitSum])
		return 1;
	return 0;

}
void seive()
{
	primes[0] = false;
	primes[1] = false;
	for(int i =2; i<= sqrt(180); i++)
	{
		if(!primes[i])
			continue;
		for(int j = 2*i; j <180; j = j+i)
		{
			primes[j] = false;
		}
	}
	return;

}
void calculate()
{
	ans =  vector<int>(INT_MAX);
	ans[0] = 0;
	ans[1] = 0;
	for(long long i =2; i <= INT_MAX; i++)
	{
		int num = i;
		int digitSum = 0;
		if(dS.find(num) != dS.end())
			digitSum= dS[num];
		else{
			while(num > 0){
				digitSum += num%10;
				num/= 10;
			}
			dS[i] = digitSum;
		}
		if(primes[digitSum])
			ans[i] = ans[i-1] + 1;

	}
}
int prime_sol(int l, int r) {
	return ans[r] - ans[l] + isPrime(l);
}

int main()
{
	
	seive();
	calculate();
	cout<<prime_sol(1, 13);
}