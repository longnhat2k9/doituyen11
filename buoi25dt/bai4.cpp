#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char, long long>x, pair<char, long long>y)
{
    if(x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}

bool cmp2(pair<char, long long>x, pair<char, long long>y)
{
    if(x.first == y.first) return x.second < y.second;
    return x.first > y.first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, q; cin >> n >> q; 
    // cin.ignore(); 
    string s;
    cin >> s; 
    // getline(cin, s);
    // cout << s << endl;

    long long cnt0 = 0, cnt1 = 0;
    for(long long i = 0; i < q; i++)
    {
        long long x; cin >> x;
        if(x == 0) cnt0++;
        else cnt1++;
    }

    vector<pair<char, long long>>a(n);
    vector<long long>d(n, 0);

    for(long long i = 0; i < n; i++)
    {
        a[i] = {s[i], i};
    }

    sort(a.begin(), a.end(), cmp);
    
    for(long long i = 0; i < cnt0; i++)
    {
        d[a[i].second] = 1;
        // cout << a[i].second << endl;
    }
    
    sort(a.begin(), a.end(), cmp2);
    
    for(long long i = 0; i < cnt1; i++)
    {
        d[a[i].second] = 1;
        // cout << a[i].second << endl;
    }
    
    for(long long i = 0; i < n; i++)
    {
        if(d[i] == 0) cout << s[i];
    }

    return 0;
}