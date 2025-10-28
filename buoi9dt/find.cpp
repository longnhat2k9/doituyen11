#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<pair<long long, long long>>v(n);

    for(long long i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    long long fi = v[0].first, se = v[0].second, mx = 0;

    for(long long i = 1; i < n; i++)
    {
        if(v[i].first <= se) 
        {
            fi = min(v[i].first, fi);
            se = max(v[i].second, se);
        }
        else
        {
            mx = max(mx, se - fi);
            fi = v[i].first;
            se = v[i].second;
        }
    }

    mx = max(mx, se - fi);

    cout << mx;
}
