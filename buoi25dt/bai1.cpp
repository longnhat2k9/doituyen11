#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; getline(cin, s);

    long long sum = 0;
    string v = "";
    
    for(auto &x : s)
    {
        if('0' <= x && x <= '9')
        {
            sum += x - '0';
        }
        else v += x;
    }

    reverse(v.begin(), v.end());
    if(v.size() == 0) v = "-1";
    cout << sum << "\n" << v << "\n";

    return 0;
}