#include<bits/stdc++.h>
using namespace std;

long long ck(long long m, const vector<long long>&a, long long n)
{
    long long t = 0;
    for(long long i = n / 2; a[i] < m && i < n; i++)
    {
        t += m - a[i];
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    vector<long long>a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long long l = a[n / 2], r = l + k, m, ans = l;
    while(l <= r)
    {
        m = (l + r) / 2;
        long long t = ck(m, a, n);
        if(t <= k) ans = max(ans, m), l = m + 1;
        else r = m - 1;
    }
    cout << ans << endl;

    return 0;
}