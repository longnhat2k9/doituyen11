#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n, k; cin >> n >> k;
    vector<long long>a(n + 1, 0);
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    long long mx = 0;
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = i; j <= n; j++)
        {
            if(a[j] - a[i - 1] >= k) mx = max((a[j] - a[i - 1]) / (j - i + 1), mx);
        }
    }

    cout << mx << endl;

    return 0;
}