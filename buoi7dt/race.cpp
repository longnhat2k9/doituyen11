#include<bits/stdc++.h>
using namespace std;

long long n, m, a[3000][3000], dp[3000], mn = 1e18, t = 0, ans[3000];

void print()
{
    cout << mn << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << a[i][ans[i]] << " ";
    }
}

void exp()
{
    if(t < mn)
    {
        mn = t;
        for(int i = 1; i <= n; i++)
        {
            ans[i] = dp[i];
        }
    }
}

void cs(int j)
{
    if(j == 1) for(int i = 1; i <= m; i++)
    {
        dp[j] = i;
        t += a[j][i];
        if(j < n) cs(j + 1);
        else exp();
        t -= a[j][i];
    }
    else for(int i = max(dp[j - 1] - 1, 1ll); i <= min(dp[j - 1] + 1, m); i++)
    {
        dp[j] = i;
        t += a[j][i];
        if(j < n) cs(j + 1);
        else exp();
        t -= a[j][i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dp, 0, sizeof(dp));
    memset(ans, 0, sizeof(ans));
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    cs(1);
    print();

    return 0;
}