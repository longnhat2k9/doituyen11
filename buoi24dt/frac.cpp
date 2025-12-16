#include<bits/stdc++.h>
using namespace std;

long long ucln (long long a, long long b)
{
    long long r;
    while(a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long a, b, c, d; cin >> a >> b >> c >> d;
    long long q = ucln(a, b);
    a /= q; b /= q;
    q = ucln(c, d);
    c /= q; d /= q;
    long long tu = ucln(a, c), mau = ((b * d) / ucln(b, d));
    q = ucln(tu, mau);
    cout << tu / q << endl << mau / q;

    return 0;
}