#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, cnt = 0; cin >> n;
    unordered_map<long long, long long>mp;
    long long a[n + 1]; a[0] = 0; mp[0]++;
    for(long long i = 1; i <= n; i++) 
    {
        cin >> a[i];
        a[i] += a[i - 1];
        mp[a[i]]++;
    }

    for(auto &x : mp)
    {
        if(x.first == 0) ((x.second * (x.second + 1)) / 2);
        cnt += ((x.second * (x.second - 1)) / 2);
    }

    cout << cnt << endl;

    return 0;
}