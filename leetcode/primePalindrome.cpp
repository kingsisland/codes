#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPrime(string s)
    {   
        int num = stoi(s);
        if (num == 1) return false;
        for(int i = 2; i <= int(sqrt(num)); i++)
        {
            if(num % i == 0)
            {
                return false;
            }
        }
        
        return true;    
    }
    
    void makePalindrome(string &s)
    {   int len = s.length() - 1;
        for(int i = 0; i <= len/2; i++)
        {   //char minDigit;
            if(s[i] < s[len - i]){
                //minDigit = s[i];
                s[i] = s[len-i] = s[i];
            }
            else if(s[i] > s[len-i]){
                //minDigit = s[len-i];
                s[i] = s[len-i] = s[len-i];
            }

        }
        if(s[0] == '0')
            s[0] = s[len] = '1';
    }

    void generateNextPalindrome(string &s)
    {   if(s == "9")
        {
            s = "11";
            return;
        }
        // Deals with all the cases which tend to increase the number of digits in the resulting palindrome
        bool flag = true;
        for(int i = 0; i< s.length(); i++)
        {
            if(s[i] != '9')
            {
                flag = false;
                break;
            }

        }
        if(flag)
        {   int s_int = stoi(s);
            s_int+=2;

            s = to_string(s_int);
            if(s.length()%2 == 0)
                s.insert(s.length()/2, 1,'0');
            //cout<<"New palindrome: "<<s<<endl;
            return;
        }
        
        if(s.length() % 2 == 1)
        {   int len = (s.length()+1)/2;
            // find the root of the palindrome
            string r = s.substr(0, len);
            int root = stoi(r);

            root++;
            r = to_string(root);
            for(int i = r.length() -2; i >=0; i--)
                r.push_back(r[i]);
            s = r;
            return;
            
        }
        else         
        {   //r.push_back('0');
            s[0] = s[s.length() - 1] = '1';
            for(int i = 1; i< s.length()/2; i++)
            {
                s[i] = s[s.length() - 1 - i] = '0';

            }
            s.insert(s.length()/2, 1, '0');
            return;
            
        }
        
     
        //cout<<"New palindrome: "<<s<<endl;
        return;
    }
    
    int primePalindrome(int N) {
        string s = to_string(N);
        int len = s.length();
  
        // convert the number into the nearest palindrome
        makePalindrome(s);
        cout<<"Palindrome : "<<s<<endl;
        
        //int i =0;
        while(true){
            if(checkIfPrime(s)){
                int res = stoi(s);
                if(res >= N) return res;
            }
            generateNextPalindrome(s);


        }
    
        return -1;
      
        
    }
};

int main()
{
    Solution solution = Solution();
    int N;
    cin>>N;
    cout<<solution.primePalindrome(N);
    // string s = to_string(N);
    // solution.generateNextPalindrome(s);
    // solution.makePalindrome(s);
    // cout<<"Palindrome : "<<s<<endl;
}