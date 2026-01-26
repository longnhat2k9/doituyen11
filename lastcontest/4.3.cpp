#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n, k; cin >> n >> k;

    vector<long long>a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    vector<long long>dp = b, mx = dp;

    for(long long i = 1; i < n; i++)
    {
        auto it = upper_bound(a.begin(), a.begin() + i, a[i] - k);        
        if(it != a.begin()) dp[i] = max(dp[i], mx[it - 1 - a.begin()] + b[i]);
        mx[i] = max(mx[i - 1], dp[i]);
    }

    cout << mx[n - 1];

    return 0;
}