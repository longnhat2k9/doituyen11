#include <bits/stdc++.h>
using namespace std;

static const long long mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    long long a = 0, ab = 0, abc = 0;

    for (auto x : s) {
        if (x == 'a') 
        {
            a = (a + 1) % mod;
        } 
        else if (x == 'b') 
        {
            ab = (2 * ab + a) % mod;
        } 
        else if (x == 'c') 
        {
            abc = (abc + ab) % mod;
        }
    }

    if (abc == 0) cout << -1;
    else cout << abc;

    return 0;
}