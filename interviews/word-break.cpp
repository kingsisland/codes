unordered_map<int,int> dp;
int solve(int state, int n, vector<vector<int>> &splits){
    //cout<<"State "<<state<<endl;
    if(state == n) return 1;
    if(dp.find(state) != dp.end()) return dp[state];
    for(auto it =  splits[state].rbegin(); it != splits[state].rend(); it++ )
        if(solve(*it+1, n, splits))
        {
            dp[state] = 1;
            return 1;
        }
    dp[state] = 0;
    return 0;
} 

int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dic;
    for(auto val : B)
        dic.insert(val);
    
    int n =A.length();
    vector<vector<int>> splits(n);
    for(int i =0; i<n; i++)
    {
        string key;
        for(int j =i; j<n; j++)
        {
            key += A[j];
            if(dic.find(key) != dic.end())
            {
                //cout<<"Yes"<<key<<endl;
                splits[i].push_back(j);
            }
               
        }
    }
    dp.clear();
    return solve(0, n, splits);
}
