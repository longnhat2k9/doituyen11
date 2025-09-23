#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n; cin >> n;
    vector<long long>a(n + 1, 0);
    for(long long i = 1; i <= sqrt(n); i++)
    {
    	for(long long j = i; j <= n; j += i) a[j]++;
    }

	long long mx = 0, mxn = 0;

	for(long long i = 1; i <= n; i++)
	{
		if(mx < a[i])
		{
			mx = a[i];
			mxn = i;
		}
	}

	cout << mxn << endl;

    return 0;
}