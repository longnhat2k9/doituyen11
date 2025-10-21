#include<bits/stdc++.h>
using namespace std;

/*
Quy uoc
1 -> +
0 -> -
*/

int n, a[200], d[200], k;

void exp(int s)
{
    if(s == k)
    {
        for(int i = 2; i <= n; i++)
        {
            if(d[i] == 1) cout << '+';
            else cout << '-';
        }
        exit(0);
    }
}

void cs(int j, int s)
{
    for(int i = 0; i <= 1; i++)
    {
        d[j] = i;
        if(i == 0) s -= a[j];
        else s += a[j];
        if(j < n) cs(j + 1, s);
        else exp(s);
        if(i == 0) s += a[j];
        else s -= a[j];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(d, 0, sizeof(d));
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    d[1] = 1;
    cs(2, a[1]);

    return 0;
}