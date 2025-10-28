#include <bits/stdc++.h>
using namespace std;

long long n, s;
long long a[6000], f[6000], sum = 0, cnt = 0;

void cs(int j, int m, vector<long long>&t)
{
    for(long long i = 0; i <= 1; i++)
    {
        f[j] = i;
        if(i == 1) sum += a[j];
        if(sum <= s) 
        {
            if(j == m) t.push_back(sum);
            if(j <= m) cs(j + 1, m, t);
        }
        if(i == 1) sum -= a[j];
    }
}

void sub1()
{
    vector<long long>t1, t2;
    cs(1, n / 2, t1);
    cs(n / 2 + 1, n, t2);
    
    sort(t1.begin(), t1.end());
    for(auto &x : t2)
    {
        cnt += upper_bound(t1.begin(), t1.end(), s - x) - lower_bound(t1.begin(), t1.end(), s - x);
    }
    cout << cnt % 123456789 << endl;
}

void sub2()
{
    __int128 dp[6000];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = min(sum, s - a[i]); j >= 0; j--)
        {
            if(dp[j] > 0)
            {
                dp[j + a[i]] += dp[j];
                sum = max(sum, j + a[i]);
            } 
        }
    }
    dp[s] %= 123456789;
    long long ans = dp[s];
    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    memset(f, 0, sizeof(f));
    cin >> n >> s;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    if(n > 40) sub2();
    else sub1();
    return 0;
}
