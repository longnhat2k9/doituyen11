#include<bits/stdc++.h>
using namespace std;

int n, m, a[30][30], dp[30], ans[30], d[30], sum = 3000;

void exp(int s)
{
    if(a[dp[n]][1] > -1)
    {
        s += a[dp[n]][1];
        if(s < sum)
        {
            sum = s;
            for(int i = 1; i <= n; i++)
            {
                ans[i] = dp[i];
            }
        }
        ans[n + 1] = 1;
    }
}

void cs(int j, int s)
{
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 0 && a[dp[j - 1]][i] != -1)
        {
            d[i] = 1;
            dp[j] = i;
            s += a[dp[j - 1]][i];
            if(j == n) exp(s);
            else cs(j + 1, s);
            s -= a[dp[j - 1]][i];
            d[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(a, -1, sizeof(a));
    memset(d, 0, sizeof(d));
    memset(dp, 0, sizeof(dp));
    memset(ans, 0, sizeof(ans));
    cin >> n >> m;
    d[1] = 1;

    for(int i = 0; i < m; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        a[x][y] = a[y][x] = z;
    }
    dp[1] = 1;
    cs(2, 0);

    for(int i = 1; i <= n + 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl << sum;


    return 0;
}