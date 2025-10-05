#include<bits/stdc++.h>
using namespace std;

#define fi first.first
#define sc first.second
#define th second

bool cmp(pair<pair<long long, long long>, long long>x, pair<pair<long long, long long>, long long>y)
{
    return x.sc < y.sc;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<pair<pair<long long, long long>, long long>>a(n);
    for(long long i = 0; i < n; i++)
    {
        cin >> a[i].fi >> a[i].sc >> a[i].th;
    }
    sort(a.begin(), a.end(), cmp);

    vector<long long>lis, f(n, -1);
    long long mxl = -1;

    for(long long i = 0; i < n; i++)
    {
        auto it = upper_bound(lis.begin(), lis.end(), a[i].fi);

        if(it == lis.end())
        {
            lis.push_back(a[i].sc);
            f[i] = lis.size();
            mxl = i;
        }
        else
        {
            *it = min(*it, a[i].sc);
            f[i] = it - lis.begin() + 1;
        }
    }

    vector<pair<pair<long long, long long>, long long>> kq;
    kq.push_back(a[mxl]);
    long long kb = mxl;
    for(long long i = mxl - 1; i >= 0; i--)
    {
        if(a[kb].fi >= a[i].sc && f[kb] > f[i])
        {
            kq.push_back(a[i]);
            kb = i;
        }
    }

    reverse(kq.begin(), kq.end());

    cout << kq.size() << endl;
    for(auto &x : kq) cout << x.fi << " " << x.sc << " " << x.th << endl;

    return 0;
}