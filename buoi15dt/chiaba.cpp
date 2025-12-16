#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n; 
    vector<long long>a(n + 1, 0);
    for(long long i = 1; i <= n; i++) 
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    if(a[n] % 3 != 0)
    {
        cout << 0;
        return 0;
    }

    long long cnt1 = 0, cnt2 = 0;
    for(long long i = 1; i < n; i++)
    {
        if(a[i] == ((a[n] / 3) * 2)) cnt2 += cnt1;
        if(a[i] == (a[n] / 3)) cnt1++;
    }

    cout << cnt2;
}