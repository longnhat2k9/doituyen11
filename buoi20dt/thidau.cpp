#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    map<long long, long long>mp;
    vector<long long>a(n + 1, 0), b(n + 1, 0);
    for(long long i = 1; i <= n; i++) cin >> a[i];
    for(long long i = 1; i <= n; i++) cin >> b[i];
    vector<long long>m(n + 1, 0), dp(n + 1, 0);

    for(long long i = 1; i <= n; i++)
    {
        long long j = upper_bound(a.begin(), a.end(), a[i] - k) - a.begin() - 1;
        dp[i] = m[max(j, 0ll)] + b[i];
        m[i] = max(m[i - 1], dp[i]);
    }
    cout << m[n] << endl;
}
