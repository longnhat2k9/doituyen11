#include<bits/stdc++.h>
using namespace std;

int n, m, dp[11], d[11], cnt = 0;

void exp()
{
    for(int i = 1; i <= m; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    cnt++;
}

void cs(int j)
{
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 0)
        {
            d[i] = 1;
            dp[j] = i;
            if(j == m) exp();
            else cs(j + 1);
            d[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dp, 0, sizeof(dp));
    memset(d, 0, sizeof(d));

    cin >> n >> m;
    
    cs(1);
    cout << cnt;
    return 0;
}