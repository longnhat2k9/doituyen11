#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long>x, pair<long long, long long>y)
{
    return x.second < y.second;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<pair<long long, long long>>a(n);
    for(long long i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), cmp);

    vector<long long>lis;
    long long f[n]; memset(f, -1, sizeof(f));
    long long mxl = -1;

    for(long long i = 0; i < n; i++)
    {
        auto it = upper_bound(lis.begin(), lis.end(), a[i].first);
        if(it == lis.end())
        {
            lis.push_back(a[i].second);
            f[i] = lis.size();
            mxl = i;
        }
        else
        {
            *it = min(*it, a[i].second);
            f[i] = it - lis.begin() + 1;
        }
    }

    vector<pair<long long, long long>> kq;
    kq.push_back(a[mxl]);
    long long kb = mxl;
    for(long long i = mxl - 1; i >= 0; i--)
    {
        if(a[kb].first > a[i].second && f[kb] > f[i])
        {
            kq.push_back(a[i]);
            kb = i;
        }
    }

    reverse(kq.begin(), kq.end());

    cout << kq.size() << endl;
    for(auto &x : kq) cout << x.first << " " << x.second << endl;

    return 0;
}