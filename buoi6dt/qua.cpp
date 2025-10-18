#include<bits/stdc++.h>
using namespace std;

int n;
const int M = 1e3 + 10;
int a[M][M], dp[M + 1];
int cnt  = 0;

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