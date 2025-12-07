#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n, q; cin >> n >> q;
    vector<long long>a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    for(long long i = 0; i < q; i++)
    {
        long long x, y; cin >> x >> y;
        cout << upper_bound(a.begin(), a.end(), y) - lower_bound(a.begin(), a.end(), x) << endl;
    }

    return 0;
}