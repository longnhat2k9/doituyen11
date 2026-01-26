#include<bits/stdc++.h>
using namespace std;

const long long mxn = 5 * 1e5;
vector<long long>a(mxn);
long long n, w;

bool ck(long long m)
{
    long long cnt = 0;
    for(long long i = 1; i <= n; i++)
    {
        if(a[i] < m) cnt += m - a[i];
    }

    return cnt <= w;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> w;
    long long l = 1e18, r = 0;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
        l = min(l, a[i]);
    }

    r += w;
    long long m, ans;

    while(l <= r)
    {
        m = (l + r) / 2;

        if(ck(m))
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << ans;
}