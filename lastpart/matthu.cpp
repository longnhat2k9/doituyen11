#include<bits/stdc++.h>
using namespace std;

void cs()
{
    long long n, m, k, x; 
    cin >> n >> m >> k >> x;
    string str; cin >> str;
    vector<string>s(m);
    vector<char>ch(m);
    for(auto &h : s) cin >> h, sort(h.begin(), h.end());
    x--;

    for(long long i = 0; i < m; i++)
    {
        long long mu = 1;
        for(long long j = 0; j < m - 1 - i; j++)
        {
            mu *= k;
            if(mu > x + 1) break;
        }

        if(mu > x + 1) ch[i] = s[i][0];
        else
        {
            ch[i] = s[i][x / mu];
            x %= mu;
        }
    }

    auto it = ch.begin();
    for(auto &h : str)
    {
        if(h == '#') 
        {
            h = *it;
            it++;
        }
    }

    cout << str;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("i", "r", stdin);
    // freopen("o", "w", stdout);

    cs();

}