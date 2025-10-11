#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long m, n; cin >> m >> n;
    long long a[m + 1], b[n + 1], f[m + 1][n + 1];
    for(long long i = 1; i <= m; i++) cin >> a[i];
    for(long long i = 1; i <= n; i++) cin >> b[i];
    memset(f, 0, sizeof(f));
    int mark[m];
    memset(mark, 0, sizeof(mark));
    long long mx = 0;

    for(long long i = 1; i <= m; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            if(a[i] == b[j]) 
            {
                f[i][j] = f[i - 1][j - 1] + 1;
                if(f[i][j] > mx)
                {
                    mx = f[i][j];
                    mark[i] = 1;
                }
            }
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }

    cout << f[m][n] << endl;

    for(long long i = 1; i <= m; i++) if(mark[i] == 1) cout << a[i] << " ";

    return 0;
}