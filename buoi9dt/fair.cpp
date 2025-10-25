#include<bits/stdc++.h>
using namespace std;

long long n, s, cnt = 0; 
long long a[6000], d[6000], dp[6000];

void cs(long long j, long long sum)
{
    for(long long i = dp[j - 1] + 1; i <= n; i++)
    {
        if(d[i] == 0)
        {
            d[i] = 1;
            sum += a[i];
            dp[j] = i;
            if(sum < s) cs(j + 1, sum);
            else if(sum == s) cnt++;
            sum -= a[i];
            d[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(d, 0, sizeof(d));
    memset(dp, 0, sizeof(dp));
    cin >> n >> s;
    for(long long i = 1; i <= n; i++) cin >> a[i];

    cs(1, 0);
    cout << cnt % 123456789;
}
