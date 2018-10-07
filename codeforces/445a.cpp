#include <bits/stdc++.h>
using namespace std;

//int sx[] = {1,-1,0,0};
//int sy[] = {0,0,1,-1};

// void bfs (char chess[105][105],int u,int v,int n,int m)
// {	
// 	bool visited[105][105];
// 	int x,y;
// 	pair <int,int> pos;
// 	for (int a = 0; a <105 ; ++a)
// 	{
// 		for(int b=0;b<105;b++)
// 		{	visited[a][b]=false;
// 		}
// 	}
// 	//queue < pair <int,int> > q;
// 	stack < pair <int,int> > q;
// 	q.push(make_pair(u,v));
// 	visited[u][v]=true;
// 	if(chess[u][v] == '.')
// 	{	chess[x][y]='W';
		
// 	}
// 	while(!q.empty())
// 	{	//pos=q.front();
// 		pos=q.top();
// 		q.pop();
// 		//visited[pos.first][pos.second]=true;
// 		//cout<<"\n In x:"<<pos.first<<" and y: "<<pos.second<<endl;
// 		for (int i = 0; i < 4; ++i)
// 		{	x=pos.first+sx[i];
// 			y=pos.second+sy[i];
// 			if(0<=x && x<n && 0<=y && y<m && visited[x][y] == false )
// 			{	
// 				visited[x][y]=true;
// 				//cout<<"\n under Parent In x:"<<x<<" and y: "<<y<<endl;
// 				q.push(make_pair(x,y));
// 				if(chess[x][y]=='.')
// 				{	//cout<<"\n Changed char under Parent In x:"<<x<<" and y: "<<y<<endl;
// 					if(chess[pos.first][pos.second]== 'W' )
// 					{
// 						chess[x][y]='B';
// 					}
// 					else if(chess[pos.first][pos.second]== 'B')
// 					{
// 						chess[x][y]='W';
// 					}
// 					else
// 					{	//chess[x][y]='W';
// 						if(rand()%2)
// 							chess[x][y]='W';
// 						else
// 							chess[x][y]='B';

// 					}
// 				}
// 			}

// 		}

// 	}
// }


int main()
{
	int n,m;
	cin>>n>>m;
	string pos;
	char chess[105][105];
	for (int i = 0; i < n; ++i)
	{	cin>>pos;
		for (int j = 0; j < m; ++j)
		{	chess[i][j]=pos[j];
			if( (i+1)%2 == 1 )
			{
				if((j+1)%2 ==1 &&chess[i][j] == '.' )
				{	chess[i][j]='B';

				}
				if((j+1)%2 ==0 && chess[i][j] == '.' )
				{	chess[i][j]='W';

				}	
			}
			else
			{	if((j+1)%2 ==1 &&chess[i][j] == '.' )
				{	chess[i][j]='W';

				}
				if((j+1)%2 ==0 && chess[i][j] == '.' )
				{	chess[i][j]='B';

				}	


			}
			
		}
	}
 	//bfs(chess,0,0,n,m);
	for (int i = 0; i < n; ++i)
	{	
		for (int j = 0; j < m; ++j)
		{	cout<<chess[i][j];
			
		}
		cout<<endl;
	}
	






	
	return 0;
}