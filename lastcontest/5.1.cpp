#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;

    if(n < 1e6)
    {
        string s = "", u = "";

        long long st = 1;
        for(; s.size() <= n; st++)
        {
            u += to_string(st);
            s += u;
            if(st == 9) st = 0;
        }

        cout << s[n - 1];
    }
    else
    {
        long long st = 1;
        long long t = 1;
        while((t * (t + 1)) / 2 <= n) t++;
        t--;
        n -= (t * (t + 1)) / 2;
        n %= 9;
        if(n == 0) cout << 9;
        else cout << n;
    }
}