#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int>a(n);

    int x, y; 
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i] = x;
    }

    sort(a.begin(), a.end());

    long long cnt = 1, ans = 0;

    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i - 1]) cnt++;
        else
        {
            ans += (cnt * (cnt  - 1)) / 2;
            cnt = 1;
        }
    }

    ans += (cnt * (cnt - 1)) / 2;
    cout << ans;

    return 0;
}