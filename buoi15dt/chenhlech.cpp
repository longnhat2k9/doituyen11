#include<bits/stdc++.h>
using namespace std;

const long long M = 1e6 + 7;
long long s[M];

void sang()
{
    fill(s, s + M, 1);
    s[0] = s[1] = 0;
    for(long long i = 2; i <= sqrt(M); i++)
    {
        if(s[i] == 1) for(long long j = i * i; j <= M; j += i)
        {
            s[j] = 0;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    sang(); 
    long long n; cin >> n;

    long long a[n];
    for(long long i = 0; i < n; i++) cin >> a[i];

    long long cnt = 0;
    for(long long i = 0; i < n; i++)
    {
        for(long long j = i + 1; j < n; j++)
        {
            long long l = abs(a[i] - a[j]);
            // cout << l << " " << s[l] << endl;
            cnt += s[l];
        }
    }

    cout << cnt << endl;

    return 0;
}