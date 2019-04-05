#include <bits/stdc++.h>
using namespace std;

void fillTeams(string (&teams)[4], int &p,  int (&totGoals)[4], int (&points)[4] )
{
	for (int i = 0; i < 12; ++i)
	{		string a,b,dummy;
			int goalsA=0, goalsB=0;

			cin>>a; cin>>goalsA;
			cin>>dummy;
			cin>>goalsB; cin>>b;

			//cout<<a<<" "<<b<<" "<<goalsA<<" "<<goalsB<<" "<<p<<endl;

			int j=0;
			for ( ; j < p; ++j)
			{
				if(teams[j] == a )
					break;
			}
			if(j == p)
			{	
				//cout<<"Not found a"<<endl;

				teams[j] = a;

				p++;
			}
				totGoals[j]+=(goalsA - goalsB);
				
			
			int k=0;

			for ( ; k < p; ++k)
			{
				if(teams[k] == b )
					break;
			}
			if(k == p)
			{	
				//cout<<"Not found b"<<endl;

				teams[k] = b;

				p++;
			}
				totGoals[k]+=(goalsB- goalsA);

			

			//dealing with points
			if(goalsA == goalsB)
			{
				points[j]+=1;
				points[k]+=1;
			}
			else if(goalsA > goalsB)
			{
				points[j]+=3;
			}
			else
			{
				points[k]+=3;
			}
	}
}

void swapTeams(string (&teams)[4],   int (&totGoals)[4], int (&points)[4], int i, int j)
{		
	int tTotGoals = totGoals[i];
	totGoals[i] = totGoals[j];
	totGoals[j] = tTotGoals;

	string tName = teams[i];
	teams[i] = teams[j];
	teams[j] = tName;

	int tPoints = points[i];
	points[i] = points[j];
	points[j] = tPoints;
}
void sortTeams(string (&teams)[4],  int (&totGoals)[4], int (&points)[4])
{

	for (int i = 0; i < 4; ++i)
	{
		for (int j = i+1; j < 4; ++j)
		{
			if(points[i] < points[j])
			{	
				//cout<<"swapping :  "<<teams[i]<<"  "<<teams[j]<<endl; 
				
				swapTeams(teams, totGoals, points, i ,j);
			}
			if(points[i] == points[j] && totGoals[i] < totGoals[j] )
			{
				swapTeams(teams, totGoals, points, i ,j);
			}
		}
	}
}

int main()
{	
	int t;
	cin>>t;
	while(t--)
	{	string teams[4];
		int p=0, totGoals[4],points[4];
		memset(totGoals, 0 , sizeof(totGoals));
		memset(points, 0 , sizeof(points));

		

		fillTeams(teams,  p, totGoals, points);

		sortTeams(teams, totGoals, points);

		
		/*for (int i = 0; i < 4; ++i)
		{
			cout<<teams[i]<<"  "<<points[i]<<"  "<<totGoals[i]<<endl;
		}*/

		cout<<teams[0]<<" "<<teams[1]<<"\n";




	}
	


		return 0;

}