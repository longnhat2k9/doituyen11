#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    long long a[n];
    for(long long i = 0; i < n; i++) cin >> a[i];

    vector<long long>lis;
    long long f[n];
    memset(f, -1, sizeof(f));
    // f = loca[i-th - 1]
    long long mxl = -1;

    for(long long i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if(it == lis.end())
        {
            lis.push_back(a[i]);
            f[i] = lis.size();
            mxl = i;
        }
        else
        {
            *it = a[i];
            f[i] = it - lis.begin() + 1;
        }
    }

    vector<long long>kq;
    kq.push_back(a[mxl]);
    
    long long bk = mxl;

    for(long long i = mxl - 1; i >= 0; i--)
    {
        if(a[i] <= a[bk] && f[i] < f[bk])
        {
            bk = i;
            kq.push_back(a[i]);
        }
    }
    
    reverse(kq.begin(), kq.end());
    cout << kq.size() << endl;
    for(auto &x : kq) cout << x << " ";

    return 0;
}
