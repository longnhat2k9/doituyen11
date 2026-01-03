#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    string s; cin.ignore(); getline(cin, s);

    for(long long k = 1; k < n; k++)
    {
        bool ck = false;
        for(long long i = 0; i < n - k; i++)
        {
            for(long long j = i + 1; j < n - k + 1; j++)
            {
                if(s[i] == s[j])
                {
                    if(s.substr(i, k) == s.substr(j, k)) 
                    {
                        ck = true;
                        break;
                    }
                }
            }
            if(ck == true) break;
        }
        if(ck == false)
        {
            cout << k;
            return 0;
        }
    }

    cout << n;

    return 0;
}