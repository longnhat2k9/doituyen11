#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("xanhdep.inp", "r", stdin);
    // freopen("xanhdep.out", "w", stdout);

    long long n; cin >> n;
    long long ans = 1, cnt = 0;

    string s;
    while(n--)
    {
        cin >> s;
        cnt = 1;

        for(long long i = 1; i < s.size(); i++)
        {
            if(s[i] == s[i - 1]) cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;
}