#include<bits/stdc++.h>
using namespace std;

#define fi first.first 
#define se first.second 
#define th second 

bool cmp(pair<pair<int, int>, int>x, pair<pair<int, int>, int>y)
{
    if(x.se == y.se) return x.fi < y.fi;
    return x.se > y.se;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<pair<pair<int, int>, int>>a(n);
    int d[n]; memset(d, 0, sizeof(d));

    for(int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se, a[i].th = i;
    
    sort(a.begin(), a.end(), cmp);

    int s = 0, v = 0;
    for(int i = 0; i < n; i++)
    {
        while(s + a[i].fi <= m)
        {
            s += a[i].fi;
            v += a[i].se;
            d[i]++;
        }
    }

    cout << v << endl;
    for(int i = 0; i < n; i++)
    {
        if(d[i] > 0) cout << a[i].th + 1 << " " << d[i] << endl;
    }

    return 0;
}