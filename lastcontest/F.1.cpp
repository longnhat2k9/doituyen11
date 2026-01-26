#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9;

long long binpow(long long a, long long b)
{
    long long ans = 1;

    while(b > 0)
    {
        if(b % 2 == 1) ans *= a, ans %= mod;
        a *= a;
        a %= mod;
        b /= 2;
    }

    return ans % mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;

    long long ans = binpow(2, n - 2);
    ans %= mod;

    ans *= (n + 1) % mod;
    cout << ans % mod;
}