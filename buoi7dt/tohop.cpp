#include<bits/stdc++.h>
using namespace std;

int n, k; 
const int M = 1e6 + 7;
int x[M];

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
    for(int i = x[j - 1] + 1; i <= n; i++)
    {
        x[j] = i;
        if(j == k) exp();
        else cs(j + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    x[0] = 0;
    cs(1);

    return 0;
}