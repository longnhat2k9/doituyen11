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
    vector<pair<pair<long long, long long>, long long>>a(n + 1, {{0, 0}, 0});
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].sc >> a[i].th;
    }
    sort(a.begin() + 1, a.end(), cmp);

    vector<long long>lis(1, 0), f(n + 1, 0), val(1, 0);
    long long mxl = 0;

    for(long long i = 1; i <= n; i++)
    {
        auto it = upper_bound(lis.begin(), lis.end(), a[i].fi);

        if(it == lis.end())
        {
            lis.push_back(a[i].sc);
            f[i] = f[mxl] + a[i].th;
            val.push_back(f[i]);
            mxl = i;
        }
        else
        {
            f[i] = val[it - lis.begin() - 1] + a[i].th;
            if(f[i] > val[it - lis.begin()])
            {
                val[it - lis.begin()] = f[i];
                *it = a[i].sc;
                if(it -lis.begin() == lis.size() - 1) mxl = i;
            }
        }
    }

    vector<pair<pair<long long, long long>, long long>> kq;
    kq.push_back(a[mxl]);
    long long kb = mxl;
    for(long long i = mxl - 1; i >= 1; i--)
    {
        if(a[kb].fi >= a[i].sc && f[kb] - a[kb].th == f[i])
        {
            kq.push_back(a[i]);
            kb = i;
        }
    }

    reverse(kq.begin(), kq.end());

    cout << f[mxl] << endl;
    for(auto &x : kq) cout << x.fi << " " << x.sc << " " << x.th << endl;

    return 0;
}