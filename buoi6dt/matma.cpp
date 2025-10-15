#include<bits/stdc++.h>
using namespace std;

string s = "";
unordered_map<char, long long>mp;
long long mx = 0;
char mxchar;

void cs()
{
    long long p; cin >> p;
    if(p == 0)
    {
        char x; cin >> x;
        s += x;
        mp[x]++;
        if(mp[x] > mx)
        {
            mx = mp[x];
            mxchar = x;
        }
    }
    else
    {
        long long r; cin >> r;
        long long i = s.size() - p;
        i = max(i, 0ll);
        r += i;
        for(; i < r; i++)
        {
            s += s[i];
            mp[s[i]]++;
            if(mp[s[i]] > mx)
            {
                mx = mp[s[i]];
                mxchar = s[i];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    while(n--) cs();

    cout << mxchar << mx;

    return 0;
}

