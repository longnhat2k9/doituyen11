#include<bits/stdc++.h>
using namespace std;

long long m, n, k; 
long long a[300];
long long tong = 0, ans = 0;

void cs(long long j)
{
    for(long long i = a[j - 1]; i <= min(k, n - tong); i++)
    {
        tong += i;
        a[j] = i;
        if(tong < n && j < m) cs(j + 1);
        else if(tong == n) ans++;
        tong -= i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    memset(a, 0, sizeof(a));
    a[0] = 1;

    cs(1);
    cout << ans << endl;

    return 0;
}