#include<bits/stdc++.h>
using namespace std;

vector<long long>nto;

void sang(int n)
{
    vector<bool>a(n + 1, 1);
    a[0] = a[1] = 0;

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(a[i] == 1) for(int j = i * i; j <= n; j += i)
        {
            a[j] = 0;
        }
    }

    for(long long i = 2; i <= n; i++) if(a[i] == 1) nto.push_back(i);
}

void cs()
{
    int k, l, r; cin >> k >> l >> r;

    sang(k);

    vector<int>a(r - l + 1);
    for(int i = l; i <= r; i++) a[i - l] = i;

    for(auto &x : nto)
    {
        for(long long i = max(x * x, (l + x - 1) / x * x); i <= r; i += x)
        {
            while(a[i - l] % x == 0) a[i - l] /= x;
        }
    }

    int cnt = 0;
    for(auto &x : a) if(x <= k) cnt++;
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("i", "r", stdin);
    // freopen("o", "w", stdout);

    cs();
}