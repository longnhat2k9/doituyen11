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

    for(long long i = -1000; i <= 1000; i++)
    {
        if(k != 0 && mp[i] > 0)
        {
            cnt += mp[k + i] * mp[i];
        }
        else
        {
            cnt += (mp[i] * (mp[i] - 1));
        }
    }

    cout << cnt << endl;

    return 0;
}