#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long m, n; cin >> m >> n;
    vector<long long>a(m), b(n);
    for(long long i = 0; i < m; i++) cin >> a[i];
    for(long long i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end(), greater<long long>());
    sort(b.begin(), b.end(), greater<long long>());

    long long l = 0, r = 0, cnt = 0;
    
    while(l < m && r < n)
    {
        while(b[r] >= a[l] && r < n) r++;
        if(r < n && b[r] < a[l]) cnt++;
        l++; r++;
    }

    cout << cnt << endl;

    return 0;
}