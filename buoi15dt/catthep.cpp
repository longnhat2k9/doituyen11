#include<bits/stdc++.h>
using namespace std;

long long ck(long long m, long long a[], long long n)
{
    long long cnt = 0;
    for(long long i = 0; i < n; i++)
    {
        cnt += a[i] / m;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    long long a[n];
    long long l = 1, m, r = 0;
    for(long long i = 0; i < n; i++) cin >> a[i], r = max(r, a[i]);

    long long ans = 0;
    while(l <= r)
    {
        m = (l + r) / 2;
        long long doan = ck(m, a, n);
        if(doan >= k) ans = max(ans, m), l = m + 1;
        else r = m - 1;
    }

    cout << ans << endl;
    return 0;
}
