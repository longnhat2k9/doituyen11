#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, d, h; cin >> n >> d >> h;

    vector<long long>a(n + 1, 0);
    for(long long i = 1; i <= n; i++) cin >> a[i];

    vector<long long>dp(n + 1, 1e18), trace(n + 1, 0);
    dp[1] = a[1];

    for(long long i = 2; i <= n; i++)
    {
        for(long long j = i - 1; j >= max(1ll, i - d); j--)
        {
            if(abs(a[i] - a[j]) <= h)
            {
                if(dp[i] > dp[j] + a[i])
                {
                    dp[i] = dp[j] + a[i];
                    trace[i] = j;
                }
            }
        }
    }

    if(dp[n] == 1e18)
    {
        cout << -1;
        return 0;
    }

    vector<long long>t(1, n);
    long long j = n;

    while(trace[j] > 0)
    {
        t.push_back(trace[j]);
        j = trace[j];
    }

    if(*t.rbegin() == 1)
    {
        cout << dp[n] << "\n" << t.size() << "\n";
        for(auto it = --t.end(); it != t.begin(); it--)
        {
            cout << *it << " ";
        }
    }
    else
    {
        cout << -1;
    }
}