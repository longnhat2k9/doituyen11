#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int>a(1e6 + 7, 0), d(1e6 + 7, 0);

    long long n; cin >> n;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        if(x >= 0) a[x] = 1;
        else d[abs(x)] = 1;
    }

    for(long long i = 1e6 + 7 - 1; i >= 0; i--)
    {
        if(a[i] == 1) cout << i << " ";
    }
    
    for(long long i = 0; i < 1e6 + 7; i++)
    {
        if(d[i] == 1) cout << "-" << i << " ";
    }

    return 0;
}