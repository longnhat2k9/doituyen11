#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, k; cin >> n >> k;

	vector<long long>a(n), dp(n, 1e18); dp[n - 1] = 0;
	for(auto &x : a) cin >> x;

	for(long long i = n - 2; i >= 0; i--)
	{
		for(long long j = i + 1; j <= min(n - 1, i + k); j++)
		{
			dp[i] = min(dp[j] + abs(a[i] - a[j]), dp[i]);
		}
	}

	cout << dp[0];
}