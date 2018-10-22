#include <bits/stdc++.h>
using namespace std;
#define INV 0
long notif[300005],t=0;
long tim=0,n,q,type,x,unread=0,a;
vector <long> app[300005];
//vector <long> :: iterator itr[300005];
long itr[300005]={0};
int main()
{	

	cin>>n>>q;
	while(q--)
	{	cin>>type;
		cin>>x;	
		if(type==1)
		{	
			tim++;
			notif[tim]=x;
			app[x].push_back(tim);
			unread++;
			

		}
		else if(type==2)
		{	
			if(  app[x].size() - itr[x] > 0	)
			{
				unread=unread-( app[x].size() - itr[x] );
				//app[x].clear();
				itr[x]+=( app[x].size() - itr[x] );
			}
			
		}
		else /*if(type==3)*/
		{	
			if(x>t)
			{	for (long i = t+1; i <= x ; ++i)
				{	a=notif[i];
					//itr=app[a].begin();

					
					if( app[a][itr[a]]==i)
					{	--unread;
						itr[a]++;
						//app[a].erase(itr);
						
					}
					
				}
				t=x;
				
			}
			

		}
		cout<<unread<<"\n";

	}







	return 0;
}
