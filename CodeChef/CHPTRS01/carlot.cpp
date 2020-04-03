#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,m,n;
	//char lots[301][301];
	int left[301],right[301];
	bool valid[301];
	char val;
	cin >>t;
	while(t--)
	{
		cin>>m>>n;
		fill(valid, valid+m+1, false);

		int start=m+1,end=-1;
		for(int i=0; i<m; i++)
		{	left[i]=n+1;
			right[i]= -1;
			for(int j =0; j<n; j++)
			{
				cin>>val;
				if(val == 'P') {
					left[i] = min(left[i],j);
					right[i] = max(right[i],j);
				
					start = min(start,i);
					end = max(end, i);
					valid[i] =  true;
				}
			}
		}
		
		if(start > end) {
			cout<<"0\n";
			continue;
		}


		right[end+1] = right[end];
		left[end+1] = left[end];
		valid[end+1]  = true;
		// cout<<endl;
		// for(int i=0; i<m; i++) cout<<left[i]<<"		"<<right[i]<<endl;
		// cout<<start<<"	"<<end<<endl;

		int curPos;

		if(start%2 == 0) curPos = left[start];
		else curPos = right[start];
		int minSteps=0;

		// dOnt forget to add downward ones

		for(int i= start; i <= end; i++ )
		{	if(!valid[i]) continue;
			
			if(i%2 == 0)
			{
				minSteps+= (left[i] - curPos);
				minSteps+= (right[i]-left[i]);
				curPos = right[i];

				int idx=i+1;
				while(!valid[idx]) idx++;

				if(idx%2 == 0 && left[idx] < curPos)
				{	
					minSteps+= curPos- left[idx];
					curPos = left[idx];	
				}
				else if(idx%2 == 1 && right[idx] > curPos)
				{
					minSteps += (right[idx] - curPos );
					curPos = right[idx];
				}
					 
			}
			else
			{
				minSteps+= (curPos - right[i]);
				minSteps+= (right[i]-left[i]);
				curPos = left[i];

				int idx=i+1;
				while(!valid[idx]) idx++;


				if(idx%2 == 0 && left[idx] < curPos)
				{	
					minSteps+= curPos- left[idx];
					curPos = left[idx];	
				}
				else if(idx%2 == 1 && right[idx] > curPos)
				{
					minSteps += (right[idx] - curPos );
					curPos = right[idx];
				}

				
			}
			//cout<<"i:	"<<i<<"		minSteps: "<<minSteps<<endl;

		}
		minSteps+= (end-start);
		cout<<minSteps<<"\n";
	}
	return 0;
}