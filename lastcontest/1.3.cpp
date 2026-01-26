#include<bits/stdc++.h>
using namespace std;

bool check(long long m, const vector<long long>&a, const vector<long long> &b)
{
    long long i = 0, n = b.size();

    for(auto &x : a)
    {
        if(x < m)
        {
            if(i >= n) return 0;
            while(i < n)
            {
                if(x + b[i] >= m)
                {
                    i++;
                    break;
                }
                i++;
            }
            if(x + b[i - 1] < m) return 0;
        }
    }

    return 1;
}

void cs()
{
    long long n, n2; cin >> n >> n2;
    long long mx = 0, mn = 1e18;

    vector<long long>a(n), b(n2);

    for(auto &x : a) cin >> x, mn = min(mn, x);
    for(auto &x : b) cin >> x, mx = max(mx, x);

    long long l = mn, r = mx + mn, m, ans = 0;

    while(l <= r)
    {
        m = (l + r) / 2;

        if(check(m, a, b))
        {
            l = m + 1;
            ans = m;
        }
        else 
        {
            r = m - 1;
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("i", "r", stdin);
    // freopen("o", "w", stdout);

    cs();
}