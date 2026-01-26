#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long cnt, ans;

void cs()
{
	ans = cnt = 1;
	long long n; cin >> n;
	vector<long long>a(n); 
	for(auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	
	for(long long i = 1; i < n; i++) 
	{
		if(a[i] - a[i - 1] == 1) cnt++;
		else
		{
			if(cnt % 2 == 1) ans *= (cnt + 1) / 2;
			ans %= mod;
			cnt = 1;
		}
	}

	if(cnt % 2 == 1) ans *= (cnt + 1) / 2;
	ans %= mod;

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while(t--) cs();
}