#include <bits/stdc++.h>
using namespace std;

string sol(int A, int B)
{
	long long mainprod = 1;

	bool flag = false;
	for(int i = A; i <= B; i++) {
		mainprod *= i;
		if(mainprod > 1e18 / i) {
			flag = true;
		}
	}
	if(!flag) {
		long long prod=1;
		int count=0;
		
		for(int i=A;i<=B;i++)
			prod*=i;
		
		while(prod%10==0){
			count++;
			prod/=10;
		}
		string s=to_string(prod);
		string s1;
		if(s.size()>10){
			for(int i=0;i<5;i++) s1+=s[i];
			s1+="...";
			for(int i=s.size()-5;i<s.size();i++) s1+=s[i];
		}
		else s1=s;
		string str=s1+" * 10^"+to_string(count);    
		return str;
	}
	int c2 = 0, c5 = 0;
	long long a = A, b = B;
	for(; a <= b; a++) {
		int n = a;
		while(n % 2 == 0) {
			n /= 2;
			c2++;
		}
		while(n % 5 == 0) {
			n /= 5;
			c5++;
		}
	}

	long long firstProd = 1, lastProd = 1;
	a = A, b = B;
	for(; a <= b; a++) {
		long long n = a;
		firstProd *= n;
		lastProd *= n;
		string tmp = to_string(firstProd);
		for(int i = 0; i < int(tmp.size()) - 12; i++) {
			firstProd /= 10;
		}
		while(lastProd / 10 * 10 == lastProd) {
			lastProd /= 10;
		}
		// cerr << tmp << endl;
		lastProd %= (10000000000);
	}
	string firstStr = to_string(firstProd).substr(0, 5);
	string lastStr = to_string(lastProd);
	while(lastStr.size() < 5) {
		lastStr = '0' + lastStr;
	}
	lastStr = lastStr.substr(lastStr.size() - 5);
	string ans = firstStr + "..." + lastStr + " * 10^" + to_string(min(c2 ,c5));
	return ans;
}