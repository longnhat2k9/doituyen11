#include<bits/stdc++.h>
using namespace std;

const long long mxn = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long n, k; cin >> n >> k;
    vector<long long>a(n); 
    vector<long long>dp(k, 0);
    dp[0] = 1;
    for(auto &x : a) 
    {
        cin >> x;
        x %= k;
        vector<long long>d = dp;
        for(long long j = 0; j < k; j++)
        {
            if(d[j] > 0)
            {
                dp[(j + x) % k] += d[j];
                dp[(j + x) % k] %= mxn;
            }
        }
    }
    
    cout << (dp[0] - 1) % mxn;
}