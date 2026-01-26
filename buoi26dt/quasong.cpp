#include<bits/stdc++.h>
using namespace std;

const long long M = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;

    vector<pair<long long, long long>>v(k);
    for(auto &x : v) cin >> x.first >> x.second;

    vector<long long>d(n + 1, 0); d[1] = 1;
    vector<long long>pre(n + 1, 0); pre[1] = 1;

    for(long long i = 2; i <= n; i++)
    {
        for(auto &x : v)
        {
            long long l = max(1ll, i - x.second), r = i - x.first;
            if(l <= r) 
            {
                if(pre[r] < pre[l - 1]) d[i] += M;
                d[i] += pre[r] - pre[l - 1];
                d[i] %= M;
            }
        }
        pre[i] = pre[i - 1] + d[i];
        pre[i] %= M;
    }

    cout << d[n] % M;

    return 0;
}