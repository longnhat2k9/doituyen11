#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m, k; cin >> n >> m >> k;
    long long d[300][300];
    memset(d, 0, sizeof(d));
    d[0][0] = 1;
    
    for(long long v = 1; v <= k; v++)
    {
        for(long long s = v; s <= n; s++)
        {
            for(long long h = 1; h <= m; h++)
            {
                d[s][h] += d[s - v][h - 1];
            }
        }
    }
    
    long long ans = 0;
    for(long long i = 1; i <= m; i++) ans += d[n][i];
    
    cout << ans << endl;
    
    return 0;
}
