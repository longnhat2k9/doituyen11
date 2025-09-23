#include<bits/stdc++.h>
using namespace std;

long long a, n, mod = 1e9 + 7;

long long binpow()
{
	long long b = 1;
	while(n > 0)
	{
		if(n % 2 == 1) b *= a % mod, b %= mod;
		a *= a % mod;
		a %= mod;
		n /= 2;
	}
	return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> n;

    cout << binpow();

    return 0;
}