#include<bits/stdc++.h>
using namespace std;

long long sum(long long n)
{
    n %= 18;
    long long s = ((n * (n + 1)) / 2) % 9;
    return s;
}

void cs()
{
    long long a, b; cin >> a >> b;
    long long s = sum(b) - sum(a - 1);
    while(s <= 0) s += 9;
    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long t; cin >> t;
    while(t--) cs();

    return 0;
}