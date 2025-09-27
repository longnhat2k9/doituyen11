#include<bits/stdc++.h>
using namespace std;

const long long m = 1e6 + 7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<long long>a(m, 0);
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x; a[x]++;
    }

    long long cnt = 0;
    for(long long i = 1; i < m; i++)
    {
        if(a[i] > 1) cnt += a[i];
    }

    cout << cnt << endl;

    return 0;
}