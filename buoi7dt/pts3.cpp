#include<bits/stdc++.h>
using namespace std;

int n, s = 0;
int a[50], ans[50];
int tich = 0, l = 0;

void print()
{
    for(int i = 1; i <= l; i++)
    {
        cout << ans[i] << " ";
    }
}

void exp(int j)
{
    int cnt = 1;
    for(int i = 1; i <= j; i++)
    {
        cnt *= a[i];
    }
    if(cnt > tich)
    {
        tich = cnt;
        l = j;
        for(int i = 1; i <= j; i++)
        {
            ans[i] = a[i];
        }
    }
}

void cs(int j)
{
    for(int i = a[j - 1]; i <= n - s; i++)
    {
        a[j] = i;
        s += i;
        if(s == n) exp(j);
        else if(s > n)
        {
            s -= i;
            break;
        }
        else cs(j + 1);
        s -= i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    a[0] = 1;
    cin >> n;
    cs(1);
    print();

    return 0;
}