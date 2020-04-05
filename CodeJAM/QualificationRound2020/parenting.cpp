#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int > pairs;

int main()
{
	int t,n;
	cin>>t;

	for(int test_case = 1; test_case <= t; test_case++)
	{
		int end_cameron=0, end_jamie=0;
		vector< pair<pairs,int > > activities;
		cin>>n;
		int s,e;
		for(int i=0; i<n; i++)
		{
			cin>>s>>e;
			activities.pb( mp(mp(s,e), i));
		}
		sort(activities.begin(), activities.end());
		string y(n,' ');
		for( int i=0; i < n; i++ )
		{
			pairs activity = activities[i].first;
			int id = activities[i].second;
			if(end_cameron <= activity.first ) {
				y[id]='C';
				end_cameron = activity.second;
			}
			else if(end_jamie <= activity.first) {
				y[id]='J';
				end_jamie = activity.second;
			}
			else
			{
				y = "IMPOSSIBLE";
				break;
			}

		}

		cout<<"Case #"<<test_case<<": "<<y<<"\n";

	}
	return 0;
}