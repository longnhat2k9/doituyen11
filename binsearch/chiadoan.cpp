#include<bits/stdc++.h>
using namespace std;

long long ck(long long m, vector<long long>a)
{
    long long cnt = 0;
    for(auto &x : a) cnt += x / m;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    vector<long long>a(n);
    long long r = 0;
    for(long long i = 0; i < n; i++) cin >> a[i], r = max(r, a[i]);

    long long l = 1, m, mx = 0;

    while(l <= r)
    {
        m = (l + r) / 2;
        long long doan = ck(m, a);
        if(doan < k) r = m - 1;
        else mx = max(mx, m), l = m + 1;
    }

    cout << mx << endl;

    return 0;
}