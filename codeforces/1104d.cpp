#include <bits/stdc++.h>
using namespace std;
long range[2]={0};

void findRange(){
	long x,y;
	int flag=0;
	string r;
	x=1;y=2;
	while(flag==0)
	{	cout<<"? "<<x<<" "<<y<<"\n";
		fflush(stdout);
		cin>>r;
		if(r=="x")
		{	flag=1;
			//break;
		}
		else if(r=="y")
		{
			x=y;
			y=y*2;
		}

	}
	range[0]=x;
	range[1]=y;
	return;
}

long finalize(long x,long y){
	//cout<<"\n x: "<<x<<" "<<y<<endl;
	string r;
	if(y==x+1) {
		if(x!=1)
		{
			cout<<"? "<<x<<" "<<y<<"\n";
			fflush(stdout);
			cin>>r;
			if(r=="y")
			{	
				return x;

			}	
			if(r=="x")
			{	
				return y;
			}
		}
		else
		{
			cout<<"? 4 3\n";
			fflush(stdout);
			cin>>r;
			if(r=="x")
				return 1;
			else
				return 2;
		}
		
	}
	else if(  y-x>1)
	{	//cout<<"HI\n";
		
		long mid=(x+y)/2;
		cout<<"? "<<x<<" "<<mid<<"\n";
		fflush(stdout);
		cin>>r;
		if(r == "y")
		{	x=mid;

			return finalize(x,y);
		}
		else if(r=="x"){
			y=mid;	
			return finalize(x,y);	
		}

	}
	 
	/*else if(x==y){
		return x;
	}*/

}
int main()
{	string s;
	long x,y;
	
	while(1)
	{
		cin>>s;
		if(s == "end"){
			break;
		}
		else if(s== "mistake"){

			break;
		}
		else if(s=="start"){
			
			findRange();
			cout<<"! "<<finalize(range[0],range[1])<<"\n";
			

		}
	}
	return 0;
}