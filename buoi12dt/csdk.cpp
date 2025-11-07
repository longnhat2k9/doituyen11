#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    unordered_map<long long, long long>mp;
    long long a[n + 1]; a[0] = 0;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        a[i] %= k;
        mp[a[i]]++;
    }

    long long cnt = 0;
    for(auto &x : mp)
    {
        if(x.first == 0) cnt += ((x.second * (x.second + 1)) / 2);
        else cnt += ((x.second * (x.second - 1)) / 2);
    }

    cout << cnt;

    return 0;
}