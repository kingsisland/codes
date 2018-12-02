#include<bits/stdc++.h>
using namespace std;
struct Process{
	
	int pid;
	int burst_time;
	int arrival_time;
	int flag;
};
bool burst_time_sort(Process p1,Process p2)
{
    return (p1.burst_time < p2.burst_time);
}
int main()
{	
//     Process proc[] = { { 1, 6, 1 }, { 2, 8, 1 },
//                     { 3, 7, 2 }, { 4, 3, 3 } };
//     int n = sizeof(proc) / sizeof(proc[0]);
	Process proc[]={{1,6,1,0},{2,8,1,0},{3,7,2,0},{4,3,3,0}};
	int n=sizeof(proc)/sizeof(proc[0]);
	int wt[n],tat[n],ct[n];float atat=0,awt=0;
	int complete=0,min_burst=999999,time=1;
	//sort(proc,proc+n,burst_time_sort);
	//	int t=0;
	while(complete<n )
	{	//t++;
			cout<<"yea\n";
			//int i=0;
			
		for (int i = 0; i < n; ++i)
		{	sort(proc,proc+n,burst_time_sort);
			cout<<"In the for loop with I : "<<i<<endl;
			//proc[i].burst_time<=min_burst &&
			if ( proc[i].burst_time>0 && proc[i].arrival_time<=time)
			{	cout<<"\n\n\t FOUND A MATCH : burst time : "<<proc[i].burst_time<<" \t time : "<<time<<" arrival_time : "<<proc[i].arrival_time<<"\t proc ID : "<<proc[i].pid<<endl;
				time++;
				--proc[i].burst_time;
				// min_burst=proc[i].burst_time;
				// if (min_burst==0)
				// {
				// 	min_burst=
				// }
				break;
			}
			else if (proc[i].burst_time==0 && proc[i].flag!=1)
			{
				complete++;
				ct[proc[i].pid]=time;
				proc[i].flag=1;
				tat[proc[i].pid]=ct[proc[i].pid]-proc[i].arrival_time;
				wt[proc[i].pid]=tat[proc[i].pid]-proc[i].burst_time;
				break;

			}
		}
				

	}
	for (int i = 0; i < n; ++i)
	{
		atat+=tat[i];
		awt+=wt[i];
	}
	atat=atat/n;
	awt=awt/n;


   cout<<"\n ATAT : "<<atat<<endl<<"\n AWT : "<<awt<<endl;
   return 0;

}