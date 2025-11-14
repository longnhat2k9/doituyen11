#include<bits/stdc++.h>
using namespace std;

char cv(char x)
{
    x -= ('a' - 'A');
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; getline(cin, s);

    unordered_map<char, long long>mp;
    long long v = 0, lmx = 0, vmx = 0;
    for(long long i = 0; i < s.size(); i++)
    {
        if('a' <= s[i] && s[i] <= 'z') s[i] = cv(s[i]);
        mp[s[i]]++;
        if(mp[s[i]] > 1)
        {
            if(i - v > lmx) 
            {
                lmx = i - v;
                vmx = v;
            }
            for(; v < i; v++)
            {
                mp[s[v]]--;
                if(s[v] == s[i]) 
                {
                    v++;
                    break;
                }
            }
        }
    }
    if(s.size() - 1 - v > lmx) 
    {
        lmx = s.size() - 1 - v;
        vmx = v;
    }

    cout << vmx + 1 << " " << lmx;
}