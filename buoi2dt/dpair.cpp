#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    unordered_map<long long, long long>mp;

    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        mp[x]++;
    }

    long long cnt = 0;

    for(auto &x : mp)
    {
        if(k + x.first != x.first)
        {
            cnt += mp[k + x.first] * x.second;
        }
        else
        {
            cnt += (x.second * (x.second - 1)) / 2;
        }
    }

    cout << cnt << endl;

    return 0;
}