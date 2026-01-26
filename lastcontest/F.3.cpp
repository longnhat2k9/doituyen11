#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<long long>a(n);
    for(auto &x : a) cin >> x;

    vector<long long>lis;

    for(auto &x : a)
    {
        auto it = lower_bound(lis.begin(), lis.end(), x);

        if(it == lis.end())
        {
            lis.push_back(x);
        }
        else
        {
            *it = x;
        }
    }

    cout << lis.size();
}