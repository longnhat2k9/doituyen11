#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long m, n, s; cin >> m >> n >> s;
    n *= m;
    vector<long long>a(n);

    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long l = 0, r = n - 1;
    
    long long mxs = -1;

    while(l < r)
    {
        if(a[l] + a[r] > s) r--;
        else if(a[l] + a[r] <= s)
        {
            mxs = max(mxs, a[l] + a[r]);
            l++;
        }
    }

    cout << mxs;
    
    return 0;
}