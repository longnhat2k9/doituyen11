#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, s; cin >> n >> s;
    long long a[n];
    for(long long i = 0; i < n; i++) cin >> a[i];

    long long dp[s + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    long long mx = 0;
    for(long long i = 0; i < n; i++)
    {
        for(long long j = min(mx, s - a[i]); j >= 0; j--)
        {
            if(dp[j] > 0 && dp[j + a[i]] == 0) dp[j + a[i]] = a[i], mx = max(mx, j + a[i]);
            if(j + a[i] == s)
            {
                vector<long long>kq;
                while(s > 0)
                {
                    kq.push_back(dp[s]);
                    s -= dp[s];
                }
                reverse(kq.begin(), kq.end());
                for(auto &x : kq) cout << x << " ";
                return 0;
            }
        }
    }

    return 0;
}