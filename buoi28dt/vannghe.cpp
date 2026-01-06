#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, m; cin >> n >> m;
	vector<long long>s(m), t(m), c(m);
	for(long long i = 0; i < m; i++) cin >> s[i] >> t[i] >> c[i];

	vector<long long>dp(n + 1, 1e18);
	dp[0] = 0;

	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 0; j < m; j++)
		{
			if(s[j] < i && i <= t[j])
			{
				dp[i] = min(dp[i], dp[s[j]] + c[j]);
			}
		}
	}

	cout << dp[n];
}