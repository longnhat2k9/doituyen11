#include<bits/stdc++.h>
using namespace std;

const long long mod = 20240131;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    n %= mod;

    __int128 gt = 1;
    __int128 ans = 1;

    for(long long i = 2; i <= n; i++)
    {
        gt *= i; gt %= mod;
        ans += gt; ans %= mod;
    }

    n = ans; cout << n << endl;

    return 0;
}