#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    long long a[n], s = 0;
    for(long long i = 0; i < n; i++) cin >> a[i], s += a[i];

    long long dp[s + 1];
    memset(dp, 0, sizeof(dp)); dp[0] = 1;
    long long mx = 0;
    for(long long i = 0; i < n; i++)
    {
        for(long long j = min(mx, s - a[i]); j >= 0; j--)
        {
            if(dp[j] == 1)
            {
                dp[j + a[i]] = 1;
                mx = max(mx, j + a[i]);
            }
        }
    }

    for(long long i = 0; i <= s; i++)
    {
        if(dp[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << s + 1 << endl;

    return 0;
}