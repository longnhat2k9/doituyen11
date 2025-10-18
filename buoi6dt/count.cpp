#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    unordered_set<long long>mp;

    long long m, n, x; cin >> m >> n;
    for(long long i = 0; i < m; i++)
    {
        cin >> x; mp.insert(x);
    }

    long long cnt = 0;
    for(long long i = 0; i < n; i++)
    {
        cin >> x; 
        if(mp.find(x) == mp.end()) cnt++;
    }

    cout << cnt;

    return 0;
}
