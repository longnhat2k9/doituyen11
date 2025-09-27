#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    unordered_map<long long, long long>mp;
    long long n; cin >> n;
    long long mxn = 0, cnt = 0;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        mp[x]++;
        if(mp[x] > mp[mxn]) mxn = x;
        if(mp[x] == 1) cnt++;
    }

    cout << cnt << " " << mp[mxn] << endl;

    return 0;
}