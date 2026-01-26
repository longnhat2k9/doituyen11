#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    vector<long long>a(n);
    for(auto &x : a) cin >> x;

    sort(a.begin(), a.end(), greater<long long>());

    multiset<long long>m;
    long long ans = 0;
    for(long long i = 0; i < n; i++)
    {
        auto it = m.lower_bound(a[i]+k);

        if(it != m.end()) m.erase(it);
        else ans += a[i];
        m.insert(a[i]);
    }

    cout << ans;
}