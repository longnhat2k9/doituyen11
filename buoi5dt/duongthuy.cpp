#include<bits/stdc++.h>
using namespace std;

// create file duongthuy.inp before run

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("duongthuy.inp", "r", stdin);
    long long n; cin >> n;
    long long a[n + 1][n + 1], f[n + 1][n + 1];

    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));

    while(!cin.eof()) 
    {
        long long x, y; cin >> x >> y; 
        a[x][y] = 1;        
    }

    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            if(a[i][j] == 1) 
            {
                f[i][j] = f[i - 1][j - 1] + 1;
                
            }
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }

    vector<pair<long long, long long>>ans;

    long long d = f[n][n], i = n, j = n;

    while(i > 0 && j > 0)
    {
        if(a[i][j] == 1)
        {
            ans.push_back({i, j});
            i--; j--; d--;
        }
        else
        {
            if(f[i][j] == f[i - 1][j])
            {
                i--;
            }
            else j--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << f[n][n] << endl;
    for(auto &x : ans) cout << x.first << " " << x.second << endl;

    return 0;
}