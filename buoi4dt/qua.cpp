#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    long long a[n + 1], s = 0; 
    a[0] = 0;
    for(long long i = 1; i <= n; i++) cin >> a[i], s += a[i];

    long long dp[s + 1];
    memset(dp, 0, sizeof(dp)); dp[0] = 1;
    long long mx = 0;
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = min(mx, s - a[i]); j >= 0; j--)
        {
            if(dp[j] > 0 && dp[j + a[i]] == 0) dp[j + a[i]] = a[i], mx = max(mx, j + a[i]);
        }
    }

    long long x = 0;
    for(long long i = s / 2; i >= 0; i--)
    {
        if(dp[i] > 0)
        {
            x = i;
            break;
        }
    }

    long long kq[n + 1];
    memset(kq, 0, sizeof(kq));
    
    long long y = x;
    while(x > 0)
    {
        kq[dp[x]] = 1;
        x -= a[dp[x]];
    }

    for(long long i = 1; i <= n; i++)
    {
        if(kq[i] == 1)
        {
            cout << a[i] << " ";
        }
    }

    cout << y << endl;

    for(long long i = 1; i <= n; i++)
    {
        if(kq[i] == 0)
        {
            cout << a[i] << " ";
        }
    }

    cout << s - y << endl;

    return 0;
}