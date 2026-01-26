#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n;
    cin >> n;
    vector<long long>a(n + 1, 0), pfs(n + 1, 0);
    unordered_map<long long, long long>mp;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        pfs[i] = pfs[i - 1] + a[i];

    }

    long long ans = -1e18;

    for(long long i = 1; i <= n; i++)
    {
        ans = max(ans, a[i]);
        if(mp.find(a[i]) == mp.end()) mp[a[i]] = pfs[i - 1];
        else
        {
            ans = max(ans, pfs[i] - mp[a[i]]);
            mp[a[i]] = min(mp[a[i]], pfs[i - 1]);
        }
    }

    cout << ans;
}