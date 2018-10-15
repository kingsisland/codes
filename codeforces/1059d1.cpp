#include <bits/stdc++.h>
using namespace std;
int main()
{	
	long n;
	int flag=0;
	cin>>n;
	
	double x[n],y[n],r,xa,xb,temp,xmin,xmax,r1,r2,;

	for (long i = 0; i < n; ++i)
	{	
		cin>>x[i];
		
		cin>>y[i];
		
		
		if(i>0)
		{	if (y[i]*y[i-1] < 0)    //checking for input validity
			{  	cout<<"-1";
				flag=1;
				break;
			}
		}
	}

	if (flag==0)
	{	
		ru=1000000;
		rl=0;

		xmax=x[0]-sqrt( (r+y[0])*(r-y[0]) );
		xmin=x[0]+sqrt( (r+y[0])*(r-y[0]) );
		//r=(ru+rl)/2;
		while(ru>=rl)
		{	r=rl+(ru-rl)/2;
			//cout<<"\nAt the top, R: "<<r<<endl;
			for (int i = 0; i < n; ++i)
			{	cout<<"\n r: "<<r<<" and x[i]: "<<x[i]<<"  y[i]: "<<y[i]<<endl;
				temp=sqrt( (r+y[i])*(r-y[i]) );
				if(isnan(temp)==true)
				{	cout<<"\n isnan(temp) == TRUE \n ";
					rl=r+1;
					break;
				}
				cout<<"\n temp is : "<<temp<<endl;
				xb=x[i]+temp;
				xa=x[i]-temp;
				if (xmin > xb)
				{
					xmin=xb;
				}
				if (xmax < xa)
				{	xmax=xa;
				
				}
			
			}
			cout<<"\n xb-xa : "<<xb-xa<<endl;
			
			if(xb-xa <=0.000001 && xb-xa>=0)
			{	cout<<r;
				//cout<<"\nFinal R is : "<<r<<endl;
				break;
			}
			else if(xb-xa > 0.000001)
			{
				ru=r-1;

				
				cout<<"\nNew R is : "<<r<<endl;
			}
			
		}
		
		
	}






	return 0;
}