#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long m, k, n, t; cin >> m >> k >> n >> t;
    if(n + k > m) 
    {
        cout << -1 << endl;
        return 0;
    }

    long long sum = t * k + ((k * (k + 1)) / 2);
    long long a[n];
    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for(long long i = 0; i < n; i++)
    {
        if(a[i] <= k)
        {
            sum += k + 1 - a[i];
            k++;
        }
        else
        {
            break;
        }
    }
    cout << sum << endl;

    return 0;
}