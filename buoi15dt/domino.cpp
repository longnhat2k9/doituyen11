#include<bits/stdc++.h>
using namespace std;

void cs2()
{
    long long n; cin >> n; cin.ignore();
    string s; getline(cin, s);

    long long l[s.size()], r[s.size()];
    bool x = false;
    for(long long i = 0; i < s.size(); i++)
    {
        if(s[i] == 'L') r[i] = 0, x = false;
        else if(s[i] == 'R') r[i] = 1, x = true;
        else
        {
            if(x == true) r[i] = r[i - 1] + 1;
            else r[i] = 0;
        }
    } 

    x = false;
    for(long long i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == 'R') l[i] = 0, x = false;
        else if(s[i] == 'L') l[i] = 1, x = true;
        else
        {
            if(x == true) l[i] = l[i + 1] + 1;
            else l[i] = 0;
        }
    } 

    long long cnt = 0;
    for(long long i = 0; i < s.size(); i++)
    {
        if(l[i] == r[i]) cnt++;
    }
    
    cout << cnt << endl;
}

void cs()
{
    long long n; cin >> n; cin.ignore();
    string s; getline(cin, s);

    long long r = -1, cnt = 0, ro = -1;;
    for(long long i = 0; i < s.size(); i++)
    {
        if(r == -1 && s[i] == '.') cnt++;
        else if(r == -1 && ro == -1 && s[i] == 'L') cnt = 0;
        else if(s[i] == 'R') r = i;
        else if(s[i] == 'L') 
        {
            if(r != -1 && (i - r) % 2 == 0 && (i - r > 1)) cnt++;
            ro = r;
            r = -1;
        }
    }
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cs2();
}