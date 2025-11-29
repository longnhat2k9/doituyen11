#include<bits/stdc++.h>
using namespace std;

#define ll pair<pair<long long, long long>, long long> 
#define fi first.first
#define se first.second
#define th second

bool cmp(ll x, ll y)
{
    if(x.se == y.se && x.fi == y.fi) return x.th > y.th;
    else if(x.se == y.se) return x.fi < y.fi;
    else return x.se < y.se;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<ll>a(n);
    for(long long i = 0; i < n; i++) cin >> a[i].fi >> a[i].se >> a[i].th;

    sort(a.begin(), a.end(), cmp);
    vector<long long>l(n, 0);
    long long mx = 0;
    for(long long i = 0; i < n; i++) l[i] = a[i].th;
    for(long long i = 0; i < n; i++)
    {
        for(long long j = 0; j < i; j++)
        {
            if(a[i].fi >= a[j].se)l[i] = max(l[i], l[j] + a[i].th);
            // cout << l[i] << " ";
        }
        // cout << endl;
        mx = max(l[i], mx);
    }
    cout << mx << endl;
}
