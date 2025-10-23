#include<bits/stdc++.h>
using namespace std;

int n, k;
const int M = 1e6 + 7;
int d[M], x[M];

void exp()
{
    for(int i = 1; i <= k; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void cs(int j)
{
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == 0)
        {
            x[j] = i;
            d[i] = 1;
            if(j == k) exp();
            else cs(j + 1);
            d[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    memset(d, 0, n + 1);
    memset(x, 0, n + 1);
    cs(1);

    return 0;
}