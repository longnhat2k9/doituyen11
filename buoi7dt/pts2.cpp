#include<bits/stdc++.h>
using namespace std;

int n, s = 0;
int a[50];

void exp(int j)
{
    for(int i = 1; i <= j; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void cs(int j)
{
    for(int i = a[j - 1] + 1; i <= n - s; i++)
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

    a[0] = 0;
    cin >> n;
    cs(1);

    return 0;
}