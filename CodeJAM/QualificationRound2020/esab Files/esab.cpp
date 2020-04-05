#include <bits/stdc++.h>
using namespace std;

void comliment_array(int p, vector<int> &B_array, int b)
{
	for(int i =0; i<= p; i++)
	{
		B_array[i]= (B_array[i]==0)?1:0;
		B_array[b-i+1] = (B_array[b-i+1]==0)?1:0;
	}
	return;
}

void reverse_array(int p, vector<int> &B_array, int b) 
{
	for(int i=0; i<=p; i++)
	{
		int temp = B_array[i];
		B_array[i] = B_array[b-i+1];
		B_array[b-i+1] = temp;
	}
	return;
}

int main()
{	
	int t,b;
	cin>>t>>b;
	vector<int> B_array(b+1);
	while(t--)
	{
		int queries=0;
		int p=0;	// P <= b
		int same,diff;
		bool same_found=false, diff_found = false;
		while(queries < 10)
		{	p++;
			queries++;
			cout<<p<<"\n"<<flush;
			cin>>B_array[p];

			queries++;
			cout<<b-p+1<<"\n"<<flush;
			cin>>B_array[b-p+1];

			if(B_array[p] == B_array[b-p+1] && !same_found)
			{
				same_found = true;
				same = p;
			}
			else if(B_array[p] != B_array[b-p+1] && !diff_found)
			{
				diff_found = true;
				diff = p;
			}

		}

		while(p*2 < b && queries < 150)
		{	

			if((queries+1)%10 == 1)
			{
				if(same_found == true && diff_found == true)
				{	
					queries++;
					cout<<same<<"\n"<<flush;
					int same_val;
					cin>>same_val;

					queries++;
					cout<<diff<<"\n"<<flush;
					int diff_val;
					cin>>diff_val;

					if(same_val != B_array[same] 
							&& diff_val != B_array[diff]) {
						/// COMPLIMENT THE ARRAY
						comliment_array(p, B_array,b);
					}
					else if(same_val == B_array[same] 
							&& diff_val != B_array[diff]) {
						/// REVERSE THE ARRAY
						reverse_array(p,B_array,b);
					}
					else if(same_val != B_array[same] 
							&& diff_val == B_array[diff]) {
						// COMPLIMENT AND REVERSE
						comliment_array(p, B_array, b);
						reverse_array(p, B_array, b);
					}

				}
				else if (same_found == true && diff_found == false)
				{
					// ALL ARE SAME VALUES
					queries++;
					cout<<same<<"\n"<<flush;
					int same_val;
					cin>>same_val;
					if(same_val != B_array[same]) {
						// COMPLIMENT OR COMPLIMENT AND REVERSE (SAME THING)
						comliment_array(p, B_array, b);
					}

				}
				else if (same_found == false && diff_found == true)
				{	
					// ALL ARE DIFFERENT VALUES
					queries++;
					cout<<diff<<"\n"<<flush;
					int diff_val;
					cin>>diff_val;
					if(diff_val != B_array[diff]) {
						// COMPLIMENT OR EVEN REVERSE
						comliment_array(p, B_array, b);
					}

				}
			}
			else
			{
				if((queries+2)%10 == 1)
				{
					queries++;
					cout<<p<<"\n"<<flush;
					int temp;
					cin>>temp;
				}
				else{
					p++;
					queries++;
					cout<<p<<"\n"<<flush;
					cin>>B_array[p];

					queries++;
					cout<<b-p+1<<"\n"<<flush;
					cin>>B_array[b-p+1];

					if(B_array[p] == B_array[b-p+1] && !same_found)
					{
						same_found = true;
						same = p;
					}
					else if(B_array[p] != B_array[b-p+1] && !diff_found)
					{
						diff_found = true;
						diff = p;
					}
				}

			}
		}


		string ans(b,' ');
		string res;
		for(int i=1; i<=b; i++)
			ans[i-1] = (B_array[i] == 0)?'0':'1';
	
		cout<<ans<<"\n"<<flush;
		cin>>res;
		if(res == "N") break;





	}

	return 0;
}