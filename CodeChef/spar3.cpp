#include <bits/stdc++.h>
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF 1001001001
#define PI 3.1415926535897932384626
#define ERR -1e16
//for map, pair
#define mp make_pair
#define fi first
#define se second
#define M 1005
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define getI(a) scanf("%d", &a) 
using namespace std;


ll Dp[3][M][M];
bool isVisited[3][M][M];


// ll DpDown[M][M];
// bool isVisitdDown[M][M];



ll c[M][M];

int m,n;
vector< pair<int,int> > val;





ll findMaxVal(int x,int y,int dir,ll maxCount)
{		cout<<"dir : "<<dir<< "  "<< val[dir].fi<<"   "<<val[dir].sc  <<"  "<<x<<"  "<<y<<endl;

	if(x<0 || x> m || y>n || y<0)
	{		cout<<"out of bounds....\n";
			return (ll)ERR;
	}
	if(x==m && y==n)
	{
		return (maxCount+c[m][n]);
	}
	if(isVisited[dir][x][y])
		return Dp[dir][x][y];
	else
	{
		isVisited[dir][x][y]=true;
		if(dir != 2)
		{
			//Dp[dir][x][y] = max(  findMaxVal(x+val[dir].fi, y+val[dir].sc, dir, maxCount+ c[x][y]), findMaxVal(x, y+1, 2, maxCount+ c[x][y] )  );
			
			ll A = findMaxVal(x+val[dir].fi, y+val[dir].sc, dir, maxCount+ c[x][y]);
			ll B = findMaxVal(x, y+1, dir, maxCount+ c[x][y]);

			Dp[dir][x][y] = max(A, B);

			return Dp[dir][x][y];
		}
		else
		{	
			//Dp[dir][x][y] = max( max( findMaxVal(x+val[dir].fi, y+val[dir].sc, dir, maxCount+ c[x][y]), findMaxVal(x-1, y, 0, maxCount+ c[x][y] ) ),
			//	max( findMaxVal(x+val[dir].fi, y+val[dir].sc, dir, maxCount+ c[x][y]), findMaxVal(x+1, y, 1, maxCount+ c[x][y] ) ));
			
			ll A = findMaxVal(x+val[dir].fi, y+val[dir].sc, dir, maxCount+ c[x][y]);
			ll B = findMaxVal(x-1, y, 0, maxCount+ c[x][y] ) ;
			ll C = findMaxVal(x+1, y, 1, maxCount+ c[x][y] ) ;

			ll maxAB = max(A, B);
			ll maxAC = max(A, C);
			Dp[dir][x][y]= max(maxAC, maxAB);


			return Dp[dir][x][y];

		}

	}

}

int main()
{	//memset(Dp,ERR,sizeof(Dp));
	
	//memset(isVisitdDown, false, sizeof(DpDown));

	val.pb( mp(-1,0));
	val.pb( mp(1,0));
	val.pb( mp(0,1));

	int t;
	getI(t);
	

	while(t--)
	{	
		
		scanf("%d %d",&m,&n);
		--m;
		--n;
		cout<<m<< "  "<<n;
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{	isVisited[0][i][j]=false;
				isVisited[1][i][j]=false;
				isVisited[2][i][j]=false;
				scanf("%lld",&c[i][j]);
				//cin>>c[i][j];

			}
		}
			//cout<<"We;";
		cout<<findMaxVal(0,0,2,0);


	}


	
}