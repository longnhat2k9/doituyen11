#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<long long>a;

    long long n; cin >> n;
    for(long long i = 2; i <= n; i++)
    {
    	while(n % i == 0)
    	{
    		n /= i;
    		a.push_back(i);
    	}
    }

    for(long long i = 0; i < a.size() - 1; i++)
    {
    	cout << a[i] << "*";
    }
    cout << *a.rbegin() << endl;

    map<long long, long long>mp;

    for(auto &x : a)
    {
        mp[x]++;
    }

    for(auto &x : mp)
    {
        cout << x.first << "^" << x.second << " ";
    }

    return 0;
}