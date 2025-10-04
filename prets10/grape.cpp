#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    long long cnt = 1, mx = 1;

    long long pre; cin >> pre;
    long long x; 
    for(long long i = 0; i < n - 1; i++)
    {
        cin >> x;
        if(x == pre) cnt++;
        else
        {
            pre = x; 
            mx = max(mx, cnt);
            cnt = 1;
        }
    }
 
    mx = max(mx, cnt);

    cout << fixed << setprecision(4) << 1.0/mx << endl;

    return 0;
}