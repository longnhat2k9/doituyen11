#include<bits/stdc++.h>
#include <ios>
using namespace std;

vector<long long>a(1e6 + 7, 1);

void sang()
{
    a[0] = a[1] = 0;
    for(long long i = 2; i < sqrt(1e6 + 7); i++)
    {
        if(a[i] == 1) for(long long j = i * i; j < 1e6 + 7; j += i) a[j] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    sang();
    string s; getline(cin, s);
    
    long long mx = 0;
    for(long long i = 0; i < s.size(); i++)
    {
        long long num = 0;
        for(long long j = i; j <= i + 5; j++)
        {
            if('0' <= s[j] && s[j] <= '9')
            {
                num *= 10;
                num += s[j] - '0';
            }
            else break;
            if(a[num] == 1) mx = max(mx, num);
        }
    }
    cout << mx << endl;
}
