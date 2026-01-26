#include<bits/stdc++.h>
using namespace std;

bool check(long long m, vector<long long> &a, long long k)
{
    long long cnt = 0, sum = 0;
    for(auto &x : a)
    {
        sum += x;
        if(sum > m)
        {
            sum = x;
            cnt++;
        }
    }
    if(sum > 0) cnt++;
    return cnt <= k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n, k; cin >> n >> k;
    vector<long long>a(n);
    long long r = 0, l = 0;
    for(auto &x : a) cin >> x, r += x, l = max(l, x);

    long long ans = 0;
    while(l <= r)
    {
        long long m = (l + r) / 2;
        // cout << l << " " << m << " " << r << " ";

        if(check(m, a, k))
        {
            ans = m;
            r = m - 1;
        }
        else 
        {
            l = m + 1;
        }

        // cout << ans << endl;
    }

    cout << ans;

    return 0;
}