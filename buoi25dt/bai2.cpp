#include<bits/stdc++.h>
using namespace std;

const long long M = 2e6 + 10;
vector<long long>a(M + 1, 1);

void sang()
{
    a[0] = a[1] = 0;
    for(long long i = 2; i <= sqrt(M); i++)
    {
        if(a[i] == 1) for(long long j = i * i; j <= M; j += i)
        {
            a[j] = 0;
        }
    }
}

long long ck(const long long &n)
{
    long long x = n;
    long long s = 0;
    while(x > 0)
    {
        s += x % 10;
        x /= 10;
    }
    return a[s];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    sang();
    long long n; cin >> n;
    long long cnt = 0;
    while(n--)
    {
        long long x; cin >> x;
        if(a[x] == 1 && ck(x) == 1) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
