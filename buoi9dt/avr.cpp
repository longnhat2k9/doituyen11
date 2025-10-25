#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    long long a[n], b[n]; 
    for(long long i = 0; i < n; i++) cin >> a[i];
    cout << a[0] << " ";
    long long s = a[0];

    for(long long i = 1; i < n; i++)
    {
        cout << a[i] * (i + 1) - s << " ";
        s = a[i] * (i + 1);
    }

}
