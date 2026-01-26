#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n; cin >> n;
    long long cnt = 1, mx = 1;

    long long pre; cin >> pre;
    long long x; n--;
    while(n--)
    {
        cin >> x;
        if(x > pre && x % 2 == pre % 2) cnt++;
        else mx = max(mx, cnt), cnt = 1;
        pre = x;
    }

    cout << max(mx, cnt);

    return 0;
}