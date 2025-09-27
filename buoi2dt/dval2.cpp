#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    unordered_map<long long, int>mp;
    long long n; cin >> n;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        if(mp[x] == 0) cout << x << " ";
        mp[x] = 1;
    }

    return 0;
}