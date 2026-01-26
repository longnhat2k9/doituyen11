#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n, W, H; cin >> n >> W >> H;

    vector<long long>w(n + 1), c(n + 1);
    long long s = 0;
    for(long long i = 1; i <= n; i++) 
    {
        cin >> w[i] >> c[i];
        s += c[i];
    }

    long long save[s + 1][n + 1];
    long long dp[s + 1]; 
    fill(dp, dp + s + 1, 1e18);
    dp[0] = 0;
    memset(save, 0, sizeof(save));

    for(long long i = 1; i <= n; i++)
    {
        for(long long j = s; j >= c[i]; j--)
        {
            if(dp[j - c[i]] + w[i] < dp[j])
            {
                dp[j] = dp[j - c[i]] + w[i];
                for(long long x = 0; x <= n; x++)
                {
                    save[j][x] = save[j - c[i]][x];
                }

                save[j][i] = 1;
            }
        }
    }

    long long mx = 0;

    for(long long i = 0; i <= s; i++)
    {
        if(dp[i] <= W)
        {
            mx = max(mx, i);
        }
    }

    for(long long i = 0; i <= s; i++)
    {
        if(dp[i] > W)
        {
            continue;
        }

        for(long long j = 1; j <= n; j++)
        {
            if(!save[i][j] && w[j] <= H)
            {
                mx = max(mx, i + c[j]);
            }
        }
    }

    cout << mx;

    return 0;
}