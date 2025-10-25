#include<bits/stdc++.h>
using namespace std;

int n, s, dp[1000], a[1000], smax = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    cin >> n >> s; s--;

    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = min(smax, s - a[i]); j >= 0; j--)
        {
            if(dp[j] == 1 && dp[j + a[i]] == 0)
            {
                dp[j + a[i]] = 1;
                smax = max(smax, j + a[i]);
            }
        }
    }

    for(int i = s; i >= 0; i--)
    {
        if(dp[i] == 1)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}