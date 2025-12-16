#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    vector<long long>a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<long long>());

    long long s = 0;
    for(long long i = 0; i < n; i++)
    {
        if(k >= 0)
        {
            s += a[i];
            k--;
        }
        else 
        {
            s -= a[i];
        }
    }
    cout << s;
}