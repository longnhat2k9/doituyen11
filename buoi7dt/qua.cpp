#include<bits/stdc++.h>
using namespace std;

int n, a[10000][10000], dp[10000], cnt = 0;

void cs(int j)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[i][j] >= a[dp[j - 1]][j - 1])
        {
            dp[j] = i;
            if(j == n) cnt++;
            else cs(j + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    dp[1] = 1;
    cs(2);
    cout << cnt << endl;

    return 0;
}