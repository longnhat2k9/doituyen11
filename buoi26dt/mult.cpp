#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long t; cin >> t;
    long long n, x;
    while(t--)
    {
        cin >> n >> x;
        cout << x / n << "\n";
    }

    return 0;
}