#include<bits/stdc++.h>
using namespace std;

const long long mxn = 2 * 1e6 + 7;
long long n = 0, k = 0;
vector<long long>a(mxn + 1), pf(mxn + 1, 0);

bool ck(long long m)
{
    for(long long i = m; i <= n; i++)
    {
        if(pf[i] - pf[i - m] >= k) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("khlt.inp", "r", stdin);
    // freopen("khlt.out", "w", stdout);

    cin >> n >> k;

    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }

    if(pf[n] < k)
    {
        cout << -1;
        return 0;
    }

    long long l = 1, r = n, m = 0, ans = 0;

    while(l <= r)
    {
        m = (l + r) / 2;
        if(ck(m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << ans;
}