#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n; cin >> n; 
    vector<string> s(n);
    cin.ignore();
    for(auto &x : s) getline(cin, x);

    long long mxlen = 0, len = 0, mxcnt = 0;
    for(auto &x : s)
    {
        len = 0;
        for(auto &a : x)
        {
            if(a != 'W' && a != 'A' && a != 'R') len++;
            else len = 0;
            if(len == mxlen) mxcnt++;
            if(len > mxlen) mxlen = len, mxcnt = 1;
        }
    }

    if(mxlen != 0) cout << mxlen << " " << mxcnt << endl;
    else cout << "NO" << endl;

    return 0;
}