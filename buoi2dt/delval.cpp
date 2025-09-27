#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, m; cin >> n >> m;
    vector<long long>a(n); 
    unordered_map<long long, long long>mp;

    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    for(long long i = 0; i < m; i++)
    {
        long long x; cin >> x;
        mp[x]--;
    }

    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++)
    {
        if(mp[a[i]] > 0)
        {
            mp[a[i]]--;
        }
        else
        {
            a.erase(a.begin() + i);
            i--;
        }
    }

    reverse(a.begin(), a.end());

    for(auto &x : a) cout << x << " ";

    return 0;
}