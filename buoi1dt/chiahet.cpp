#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string n; getline(cin, n);

    long long s1 = 0, s2 = 0;

    for(long long i = 0; i < n.size(); i++)
    {
    	if(i % 2 == 0) s1 += n[i] - '0';
    	else s2 += n[i] - '0';
    }

    if(((s1 - s2) % 11 == 0) && ((s1 + s2) % 3 == 0)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}