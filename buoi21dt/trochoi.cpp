#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unordered_map<long long, long long>mp;
    long long n; cin >> n;
    long long ans = 0;
    vector<long long>a(n);
    for(auto &x : a) cin >> x;
    long long cnt = 0;
    for(long long i = 0; i < n - 2; i++)
    {
        cnt = 0;
        // cout << "---" << endl;
        for(long long j = i; j < n; j++)
        {
            if(a[i] == a[j] && i != j) break;
            if(mp[a[j]] == 1) mp[a[j]]++, cnt--;
            if(mp[a[j]] == 0) 
            {
                mp[a[j]]++; 
                cnt++; 
                // cout << i << " " << j << " " << cnt - 2 << endl;
                if(cnt >= 3) ans += cnt - 2;
            }
            // cout << cnt << endl;
        }
        mp.erase(mp.begin(), mp.end());
    }

    cout << ans << endl;

    return 0;
}