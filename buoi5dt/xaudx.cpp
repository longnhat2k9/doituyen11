#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s1, s2; getline(cin, s1);
    s2 = s1; reverse(s2.begin(), s2.end());
    long long n = s1.size();
    long long f[n + 1][n + 1];  
    memset(f, 0, sizeof(f));
    s1 = "0" + s1;
    s2 = "0" + s2;
    

    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            if(s1[i] == s2[j])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else 
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    long long i = n, j = n;
    long long ans[n + 1];
    memset(ans, 0, sizeof(ans));

    while(i > 0 && j > 0)
    {
        if(s1[i] == s2[j])
        {
            ans[i] = 1;
            i--; j--;
        }
        else
        {
            if(f[i - 1][j] == f[i][j]) i--;
            else j--;
        }
    }

    cout << n - f[n][n] << endl;
    for(long long i = 1; i <= n; i++)
    {
        if(ans[i] == 0) cout << s1[i] << " ";
    }

    return 0;
}