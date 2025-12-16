#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    long long a[n + 1];
    a[0] = 0;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    long long l = 0, cnt = 0;
    
    for(long long r = 1; r <= n; r++)
    {
        if(a[r] - a[l] == k) cnt++;
        while(a[r] - a[l] >= k)
        {
            l++;
            if(a[r] - a[l] == k) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}