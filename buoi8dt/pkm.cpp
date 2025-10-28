#include<bits/stdc++.h>
using namespace std;

string pkm;
long long cap = -1, tongcap = 0;

void cs()
{
    cin.ignore();
    string s; getline(cin, s);
    long long m, k, r, cnt = 0; cin >> m >> k >> r;
    if(m >= k) cnt = (m - k) / (k - r) + 1;
    cout << cnt << " ";
    tongcap += cnt;
    if(cap < cnt)
    {
        cap = cnt;
        pkm = s;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long t; cin >> t;
    while(t--) cs();
    cout << endl << tongcap << endl << pkm << endl;

    return 0;
}