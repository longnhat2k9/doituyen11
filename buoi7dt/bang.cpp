#include<bits/stdc++.h>
using namespace std;

int n, s = 0;
int a[50];

void exp(int j)
{
    for(int i = 1; i <= j; i++)
    {
        if(a[i] == 1) cout << "O";
        else cout << "T";
    }
    cout << endl;
}

void cs(int j)
{
    for(int i = 1; i <= 2; i++)
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

    cin >> n; n--;
    cs(1);

    return 0;
}