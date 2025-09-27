#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long n; cin >> n;
    vector<int>a(n + 1, 0);
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        if(x <= n && x > 0) a[x] = 1;
    }   

    for(long long i = 1; i <= n; i++)
    {
        if(a[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << n + 1 << endl;

    return 0;
}
