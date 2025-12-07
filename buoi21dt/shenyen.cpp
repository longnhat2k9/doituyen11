#include<bits/stdc++.h>
using namespace std;

long long bcnn(long long x, long long y)
{
    __int128 tich = x;
    tich *= y;
    long long r, a = x, b = y;
    while(a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    tich /= b;
    a = tich;

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n, x, y; cin >> n >> x >> y;
    long long m = bcnn(x, y);
    cout << n / m << endl;

    return 0;
}