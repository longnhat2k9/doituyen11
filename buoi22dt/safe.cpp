#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    cin.ignore();
    string s; getline(cin, s);

    long long num = 0, cap = 0, nocap = 0;

    long long l = 0, ans = 0;
    for(long long r = 0; r < n; r++)
    {
        if('A' <= s[r] && s[r] <= 'Z') cap++;
        else if('a' <= s[r] && s[r] <= 'z') nocap++;
        else num++;
        
        while(r - l + 1 >= 6 && num > 0 && cap > 0 && nocap > 0)
        {
            ans += n - r;
            if('A' <= s[l] && s[l] <= 'Z') cap--;
            else if('a' <= s[l] && s[l] <= 'z') nocap--;
            else num--;
            l++;
        }
    }

    cout << ans << endl;

    return 0;
}