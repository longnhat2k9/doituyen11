#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n; cin >> n;
    unordered_map<long long, long long>mp;
    for(long long i = 0; i < n; i++)
    {
    	long long x; cin >> x;
    	mp[x]++;
    }

    cin >> n;
    for(long long i = 0; i < n; i++)
    {
    	long long x; cin >> x;
    	cout << mp[x] << endl;
    }

    return 0;
}