#include <bits/stdc++.h>
using namespace std;
int main()
{	int t;
	long L,v,l,r,tot,nan;
	cin>>t;
	while(t--)
	{	cin>>L>>v>>l>>r;
		tot=L/v;
		//tot=tot-(r/v - l/v);
		nan=(r/v - l/v);
		//cout<<"\n nan: "<<nan<<endl;
		if(l%v==0)
		{
			nan++;

		}
		//cout<<"\n nan: "<<nan<<endl;
		// if(v==l)
		// {
		// 	nan--;
		// }
			//cout<<"\n nan: "<<nan<<endl;
		cout<<tot-nan<<endl;



	}




	return 0;
}