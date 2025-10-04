#include<bits/stdc++.h>
using namespace std;

const long long m = 1e6 + 7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<long long>a(m, 0);
    long long n; cin >> n;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        a[x] = 1;
    }

    long long sum = 0;
    for(long long i = 1; i < m; i++)
    {
        if(a[i] > 0) sum += i;
    }

    cout << sum << endl;

    return 0;
}