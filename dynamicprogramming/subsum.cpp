#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, s; cin >> n >> s;
    vector<long long>a(n + 1, 0);
    for(long long i = 1; i <= n; i++) cin >> a[i];
    vector<int>dp(s + 1, 0);
    dp[0] = 1;
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = s; j >= a[i]; j--)
        {
            dp[j] = max(dp[j - a[i]], dp[j]);
        }
    }

    cout << dp[s] << endl;

    return 0;
}