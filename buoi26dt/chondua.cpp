#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<long long>a(n);
    for(auto &x : a) cin >> x;
    
    unordered_map<long long, long long>mp;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        mp[x]++;
    }

    long long cnt = 0;
    for(auto &x : a)
    {
        cnt += n - mp[x];
    }

    cout << cnt << "\n";

    return 0;
}