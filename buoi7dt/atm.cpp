#include<bits/stdc++.h>
using namespace std;

int n, s;
int a[30], d[30];

void exp()
{
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 1) cout << a[i] << " ";
    }
    exit(0);
}

void cs(int j)
{
    for(int i = 0; i < n; i++)
    {
        if(d[i] == 0)
        {
            d[i] = 1;
            s -= a[i];
            if(s > 0) cs(j + 1);
            else if(s < 0)
            {
                s += a[i];
                d[i] = 0;
                break;
            }
            else exp();
            s += a[i];
            d[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(d, 0, 30);
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];    
    cs(1);

    return 0;
}