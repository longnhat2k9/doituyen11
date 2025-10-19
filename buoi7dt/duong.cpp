#include<bits/stdc++.h>
using namespace std;

int n, p, q, a[1000][1000], dp[1000], d[1000];

void exp(int j)
{
    for(int i = 1; i <= j; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
}

void cs(int j)
{
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 0 && a[dp[j - 1]][i] == 1)
        {
            dp[j] = i;
            d[i] = 1;
            if(i == q) 
            {
                exp(j);
            }
            else cs(j + 1);
            d[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    memset(d, 0, sizeof(d));

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> p >> q;

    dp[1] = p;
    d[p] = 1;
    cs(2); 

    return 0;
}