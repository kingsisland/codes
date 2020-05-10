#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int x,y;
    string s;
    for(int c =1; c <= t; c++)
    {
        cin>>x>>y>>s;
        bool flag = false;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == 'N')
                y +=1;
            if(s[i] == 'S')
                y -=1;
            if(s[i] == 'E')
                x +=1;
            if(s[i] == 'W')
                x -=1;
                
            if(abs(x) + abs(y) <= i+1)
            {
                cout<<"Case #"<<c<<": "<<i+1<<"\n";
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            cout<<"Case #"<<c<<": IMPOSSIBLE\n";
        }
    }
}