#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    long long k = 0;
    vector<int>a(n + 1, 0);
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        if(x > 0 && x <= n && a[x] == 0) a[x] = 1;
        else k = i;
    }

    for(long long i = 1; i <= n; i++)
    {
        if(a[i] == 0)
        {
            cout << k + 1 << " " << i << endl;
            return 0;
        }
    }

    return 0;
}