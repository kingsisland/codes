#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (long i=0; i< long(n); i++)
#define N 300005
#define INF 2000000000
long n;
long l[N],r[N];
long prl[N],prr[N],sul[N],sur[N];
int main()
{	scanf("%ld", &n);
	forn(i,n)
		scanf("%ld %ld",&l[i], &r[i]);
	prl[0]=sul[n]=0;
	prr[0]=sur[n]=INF;

	forn(i,n)
	{
		prl[i+1] = max(prl[i],l[i]);
		prr[i+1] = min(prr[i],r[i]);
	}

	for(long i=n-1; i>=0;--i)
	{
		sul[i]= max(sul[i+1],l[i]);
		sur[i] = min(sur[i+1],r[i]);
	}

	long ans=0;
	forn(i,n)
		ans = max(ans, min(sur[i+1], prr[i]) - max(prl[i], sul[i+1]));

	printf("%ld",ans );
	



	return 0;
}