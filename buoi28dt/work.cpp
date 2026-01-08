#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n; cin >> n;
	vector<long long> t(n + 1, 0), p(n, 0), dp(n + 1, 0);

	for(long long i = 1; i <= n; i++) cin >> t[i];
	for(long long i = 1; i < n; i++) cin >> p[i];

	dp[1] = t[1];

	for(long long i = 2; i <= n; i++)
	{
		dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + p[i - 1]);
	}

	cout << dp[n];
}