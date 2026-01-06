#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, q; cin >> n >> q;

	vector<long long>a(n + 1, 0), pf(n + 1, 0);
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		pf[i] = pf[i - 1] + a[i];
	}

	while(q--)
	{
		long long x; cin >> x;
		if(x == 1)
		{
			long long p,m,x; cin >> p >> m >> x;
			for(long long i = p; i <= m; i++)
			{
				a[i] += x;
				pf[i] = pf[i - 1] + a[i];
			}
			for(long long i = m + 1; i <= n; i++)
			{
				pf[i] = pf[i - 1] + a[i];
			}
		}
		else
		{
			long long u,v; cin >> u >> v;
			cout << pf[v] - pf[u - 1] << "\n";
		}
	}
}