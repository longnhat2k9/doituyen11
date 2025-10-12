#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, V; cin >> n >> V;
    vector<long long>w(n + 1, 0), v(n + 1, 0);
    long long dp[n + 1][V + 1];
    memset(dp, 0, sizeof(dp));

    for(long long i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    for(long long i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= V; j++)
        {
            if(j < w[i]) dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][V] << endl;

    return 0;
}