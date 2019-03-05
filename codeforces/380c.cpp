//incomplete

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
#include <bits/stdc++.h>

   
    long n,m,l,r,dots;
    vector <pair<long,long>> left,right;
     n=s.length();
     
    long x=0,y=1;
    long prev[n+1];
    long prefSum[n+1];
    prev[0]=-1;
   
    while(y<n)
    {   if(s[x] == '(' && s[y] == ')' )
        {   /*s[x]='.';
            s[y]='.';*/
           // cout<<s<<endl;


            left.push_back(x+1,y+1);
            right.push_back(x+1,y+1);
            
            prev[y]=prev[x];
            if( prev[x] != -1 )
            {
                x=prev[x];
                y=y+1;
            }
            else
            {
                x=y+1;
                y=y+2;
            }

        }
        else
        {
            prev[y]=x;
            x=y;
            y=y+1;
        }
    
    }


    sort



    


    
    
    
    
    
    return 0;
}
