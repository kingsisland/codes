#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i< int(n); ++i)

typedef long long li;
using namespace std;

const int LOGN = 11;
const int N = 200 * 1000 + 13;

int n,k;
int pw[LOGN];
vector <int> rems[LOGN];
int a[N];
int len[N];


int main()
{   
	scanf("%d %d",&n,&k);
	
	
	forn(i,n)
		scanf("%d",&a[i]);

	pw[0] = 1;
	forn(i, LOGN - 1)
		pw[i + 1] = pw[i] * 10 % k;

	forn(i, n){
		int x = a[i];
		while (x > 0){
			++len[i];
			x /= 10;
		}
		rems[len[i]].push_back(a[i] % k);
	}
	
	
	forn(i, LOGN)
		sort(rems[i].begin(), rems[i].end());
	
	li ans = 0;
	forn(i, n){
		for (int j = 1; j < LOGN; ++j){
			int rem = (a[i] * li(pw[j])) % k;
			int xrem = (k - rem) % k;
			auto l = lower_bound(rems[j].begin(), rems[j].end(), xrem);
			auto r = upper_bound(rems[j].begin(), rems[j].end(), xrem);
			ans += (r - l);
			if (len[i] == j && (rem + a[i] % k) % k == 0)
				--ans;
		}
	}
	
	cout<<ans;
	return 0;
}




