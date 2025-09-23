#include<bits/stdc++.h>
using namespace std;

void ck(long long n)
{
    if(n < 2) 
    {
        cout << "NO" << endl;
        exit(0);
    }
    for(long long i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    ck(abs(n));

    return 0;
}