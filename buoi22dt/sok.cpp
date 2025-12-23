#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, t; cin >> n >> t;
    set<long long>s;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        s.insert(x);
    }
    // sort(a.begin(), a.end());
    vector<long long>a;
    for(auto &x : s) a.push_back(x);

    while(t--)
    {
        long long bf = 0;
        long long x; cin >> x;
        long long now = upper_bound(a.begin(), a.end(), x) - a.begin();
        while(now != bf)
        {
            x += now - bf;
            bf = now;
            now = upper_bound(a.begin(), a.end(), x) - a.begin();
        }
        cout << x << endl;
    }

    return 0;
}
