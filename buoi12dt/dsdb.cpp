#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<long long>a(n), b;
    for(long long i = 0; i < n; i++) cin >> a[i];
    b = a;
    reverse(b.begin(), b.end());

    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for(long long i = 0; i < n; i++)
    {
        for(long long j = 0; j < n; j++)
        {
            if(a[i] == b[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j +1], dp[i + 1][j]);
            }
        }
    }

    cout << n - dp[n][n];

    return 0;
}