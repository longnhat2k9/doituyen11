#include<bits/stdc++.h>
using namespace std;

void cs()
{
    long long x, y; cin >> x >> y; x += y;

    string s = to_string(x);
    string s2 = s;
    reverse(s.begin(), s.end());
    if(s == s2) cout << 1 << endl;
    else cout << 0 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    while(n--) cs();

    return 0;
}