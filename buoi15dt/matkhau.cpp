#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; getline(cin, s);
    
    for(long long i = 1; i <= s.size(); i++)
    {
        if(s.size() % i == 0)
        {
            string s1 = s.substr(0, i);
            string s2 = s1;
            while(s2.size() < s.size())
            {
                s2 += s1;
            }
            if(s2 == s)
            {
                unordered_map<char, long long>mp;
                for(auto &x : s1)
                {
                    mp[x]++;
                }
                
                long long mx = 0; char mxchar;
                for(auto &x : mp)
                {
                    if(x.second > mx)
                    {
                        mx = x.second;
                        mxchar = x.first;
                    }
                }
                cout << mx;
                return 0;
            }
        }
    }


    
}