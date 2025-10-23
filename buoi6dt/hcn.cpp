#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long x, y, z, t, n; cin >> n;

    long long mx = -1, hx = -1;

    vector<pair<long long, long long>>a(n);
    for(long long i = 0; i < n; i++)
    {
        cin >> x >> y >> z >> t;
        a[i].first = x;
        a[i].second = z;
        if(x > mx)
        {
            mx = x;
            hx = i;
        }
    }

    long long mz = 1e6, hz = -1;
    
    for(long long i = 0; i < n; i++)
    {
        if(i != hx && a[i].second < mz)
        {
            mz = a[i].second;
            hz = i;
        }
    }

    cout << mx - mz << endl;
    cout << hz + 1 << " " << hx + 1 << endl;

    return 0;
}
