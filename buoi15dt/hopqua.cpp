#include<bits/stdc++.h>
using namespace std;

long long dem(long long x)
{
    if(x < 3) return 0;
    else
    {
        return (x * (x - 1) * (x - 2)) / 6;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, d; cin >> n >> d;
    long long mxn = 0;
    vector<long long>a(1e6 + 100, 0);
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x; mxn = max(mxn, x);
        a[x]++;
    }

    long long l = 0, cnt = 0, ans = 0;
    for(long long i = 0; i <= mxn; i++)
    {
        if(i - l < d) cnt += a[i];
        else
        {
            // cout << l << " " << i << endl;
            cnt += a[i];
            // cout << a[l] << " " << a[i] << " " << cnt << endl;
            ans += dem(cnt) - dem(cnt - a[l]);
            // cout << cnt << " " << dem(cnt, d, gt) << " " << dem(cnt - a[l], d, gt) << " " << ans << endl;
            cnt -= a[l];
            l++;
        }
    }
    ans += dem(cnt);
    cout << ans << endl;

    return 0;
}