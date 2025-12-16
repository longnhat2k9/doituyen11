#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<long long, long long>, long long>x, pair<pair<long long, long long>, long long>y)
{
    if(x.first.first == y.first.first && x.first.second == y.first.second) return x.second < y.second;
    if(x.first.first == y.first.first) return x.first.second < y.first.second;
    return x.first.first > y.first.first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, m; cin >> n >> m;
    pair<pair<long long, long long>, long long>a[n];
    memset(a, 0, sizeof(a));
    for(long long i = 0; i < n; i++)
    {
        a[i].second = i + 1;
        for(long long j = 0; j < m; j++)
        {
            long long x; cin >> x;
            if(x > 0)
            {
                a[i].first.first++;
                a[i].first.second += x;
            }
        }
    }

    sort(a, a + n, cmp);

    for(long long i = 0; i < n; i++)
    {
        if(a[i].first.first == a[0].first.first && a[i].first.second == a[0].first.second) cout << a[i].second << " ";
        else break;
    }

    return 0;
}