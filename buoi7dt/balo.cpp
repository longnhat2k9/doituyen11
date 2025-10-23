#include<bits/stdc++.h>
using namespace std;

int n, m;
const int M = 1e6 + 7;
int d[M], v[M], dp[M], mxsum = 0;

void exp()
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] == 1) sum += v[i];
    }
    mxsum = max(mxsum, sum);
}

void cs(int sum)
{
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] == 0)
        {
            dp[i] = 1;
            sum += d[i];
            if(sum < m) cs(sum);
            else if(sum > m)
            {
                dp[i] = 0;
                sum -= d[i];
                continue;
            }
            else exp();
            sum -= d[i];
            dp[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    memset(dp, 0, n + 2);
    for(long long i = 1; i <= n; i++)
    {
        cin >> d[i] >> v[i];
    }

    cs(0);

    cout << mxsum << endl;

    return 0;
}