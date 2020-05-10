#include <bits/stdc++.h>
using namespace std;

struct comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        return l.first > r.first;
    }
};
int main()
{
    int t;
    cin>>t;
    int u;
    for(int c =1; c <= t; c++)  // c == case no
    {   vector<int> freq(26,0);
        unordered_set<char> isPresent;
        cin>>u;
        long long Q;
        string R;
        int query = 1;
        for(; query<= 10000; query++)
        {
            cin>>Q>>R;
            freq[R[0]-'A']++; 
            for(auto val: R)
            {
                if(isPresent.find(val) == isPresent.end())
                    isPresent.insert(val);
            }       
        }
        set< pair<int,char>, comp > freqSet;
        for(int i =0; i < 26; i++)
        {
            if(freq[i] > 0) freqSet.insert(make_pair( freq[i], char(i+'A') ));
        }
        string ans;
        for(auto it = freqSet.begin(); it != freqSet.end(); it++)
        {
            ans.push_back((*it).second);
            isPresent.erase((*it).second);
        }
        ans.insert( ans.begin(), *(isPresent.begin()) );
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }

    return 0;
}