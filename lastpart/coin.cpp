#include<bits/stdc++.h>
using namespace std;

void cs()
{
    map<long long, long long>mp;

    long long n, m; cin >> n >> m;
    mp[n + 1] = 0;
    long long mx = 0;
    while(m--)
    {
        long long l, r; cin >> l >> r;

        if(l > r)
        {
            mp[l]++, mp[n + 1]--;
            mp[1]++, mp[r + 1]--;
        }
        else
        {
            mp[l]++, mp[r + 1]--;
        }
    }

    long long ans = 0;
    mx = mp.begin() ->second;
    for(auto it = ++mp.begin(); it != mp.end(); it++)
    {
        auto it2 = it;
        it2--;
        it -> second += it2 ->second;
        mx = max(mx, it ->second);
    }

    for(auto it = mp.begin(); it != --mp.end(); it++)
    {
        auto it2 = it;
        it2++;

        if(it->second == mx)
        {
            ans += it2->first - it->first;
        }
    }

    cout << mx << " " << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("i", "r", stdin);
    // freopen("o", "w", stdout);

    cs();

}