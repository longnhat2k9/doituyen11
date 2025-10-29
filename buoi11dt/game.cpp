#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    unordered_map<long long, vector<long long>>mp;
    for(long long i = 0; i < n; i++) 
    {
        long long x; cin >> x;
        mp[x].push_back(i + 1);
    }
    long long t; cin >> t; n = t;
    long long cnt = 0;
    while(n--)
    {
        long long x; cin >> x;
        if(mp[x].size() == 0) cout << -1 << endl;
        else cout << mp[x][0] << endl, cnt++;
    }

    if(t - cnt == cnt) cout << 0 << endl;
    else if(t - cnt < cnt) cout << 1 << endl;
    else cout << -1 << endl;

    return 0;
}