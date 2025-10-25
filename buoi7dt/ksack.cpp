#include<bits/stdc++.h>
using namespace std;

int n, m, w[10000], v[10000], s = 0, d[10000], mxval = 0, ans[10000];

void exp()
{
    int val = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 1)
        {
            val += v[i];
        }
    }
    if(val > mxval)
    {
        mxval = val;
        for(int i = 1; i <= n; i++) ans[i] = d[i];
    }
}

void cs(int j)
{
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 0)
        {
            d[i] = 1;
            s += w[i];
            if(s <= m)
            {
                exp();
                if(s < m) cs(j + 1);
            }
            d[i] = 0;
            s -= w[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(d, 0, sizeof(d)); 
    memset(ans, 0, sizeof(ans)); 
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    cs(1);

    cout << mxval << endl;
    for(int i = 1; i <= n; i++)
    {
        if(ans[i] == 1) cout << i << " ";
    }

    return 0;
}