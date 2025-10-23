#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, s; cin >> n >> s; s--;
    long long a[n + 1]; 
    for(long long i = 1; i <= n; i++) cin >> a[i];

    long long f[s + 1];
    memset(f, 0, sizeof(f)); f[0] = 1;

    long long mxsum = 0;
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = min(mxsum, s - a[i]); j >= 0; j--)
        {
            if(f[j] == 1 && f[j + a[i]] == 0)
            {
                f[j + a[i]] = 1;
                mxsum = max(mxsum, j + a[i]);
                if(j + a[i] == s) 
                {
                    cout << s;
                    return 0;
                }
            }
        }
    }

    cout << mxsum;

    return 0;
}