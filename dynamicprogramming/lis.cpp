#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<long long>a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];
    vector<long long>b(n, 1);
    long long mx = 1;
    for(long long i = 1; i < n; i++)
    {
        for(long long j = i - 1; j >= 0; j--)
        {
            if(a[i] > a[j])
            {
                b[i] = max(b[i], b[j] + 1);
            }
        }
        mx = max(mx, b[i]);
    }

    cout << mx << endl;

    return 0;
}