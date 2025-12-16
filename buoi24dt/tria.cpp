#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    map<long long, long long>mp;
    long long ans = 0;

    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        mp[x]++;
        // cout << x << " " << mp[x] << endl;
    }

    // for(auto &x : mp)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    vector<long long>a;
    for(auto &x : mp) a.push_back(x.first);

    for(auto &x : mp)
    {
        if(x.second >= 3) ans++;
        if(x.second >= 2)
        {
            auto it = lower_bound(a.begin(), a.end(), x.first * 2);
            ans += it - a.begin() - 1;
        }
    }
    cout << ans << endl;

    return 0;
}