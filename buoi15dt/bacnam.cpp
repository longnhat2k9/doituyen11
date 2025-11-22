#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<long long>a(n + 1, 0);
    for(long long i = 1; i <= n; i++)
    {
        long long x; cin >> x;
        a[x] = i;
    }

    long long bf = 0, cnt = 1;
    for(long long i = 1; i <= n; i += 2)
    {
        if(a[i] < bf) cnt++;
        bf = a[i]; 
    }
    cout << cnt << endl;
    
    bf = 0, cnt = 1;
    for(long long i = 2; i <= n; i += 2)
    {
        if(a[i] < bf) cnt++;
        bf = a[i]; 
    }
    cout << cnt << endl;

    return 0;
}