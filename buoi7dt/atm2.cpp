#include<bits/stdc++.h>
using namespace std;

int n, s, a[40], dp[40], d[40], sz = 40, ans[40];

void print()
{
    for(int i = 1; i <= sz; i++)
    {
        cout << a[ans[i]] << " ";
    }
}

void exp(int j)
{
    if(j < sz)
    {
        sz = j;
        for(int i = 1; i <= j; i++)
        {
            ans[i] = dp[i];
        }
    }
}

void cs(int j, int sum)
{
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 0)
        {
            d[i] = 1;
            dp[j] = i;
            sum += a[i];
            if(sum == s) exp(j);
            else if(sum > s)
            {
                sum -= a[i];
            }
            else cs(j + 1, sum);
            d[i] = 0;
            sum -= a[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(ans, -1, sizeof(ans));
    memset(d, 0, sizeof(d));
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cs(1, 0);
    print();

    return 0;
}