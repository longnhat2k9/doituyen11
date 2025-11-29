#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n, m; cin >> n >> m;
    long long cnt = 0;
    long long mx = 0, count = 0;
    cin.ignore();
    long long a[n][m];
    for(long long i = 0; i < n; i++)
    {
        string s; getline(cin, s);
        for(long long j = 0; j < m; j++)
        {
            a[i][j] = s[j] - '0';
            cnt += a[i][j];
            if(j != 0 && s[j] == s[j - 1] && s[j] == '1') count++;
            else count = 0;
            mx = max(mx, count);
        }
    }

    cout << cnt << " ";

    count = 0;
    for(long long j = 0; j < m; j++)
    {
        for(long long i = 0; i < n; i++)
        {
            if(i != 0 && a[i][j] == a[i - 1][j] && a[i][j] == 1) count++;
            else count = 0;
            mx = max(mx, count);
        }
    }
    cout << mx + 1 << endl;
}
