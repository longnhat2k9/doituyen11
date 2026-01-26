#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, c1 = 0, c2 = 0, c0 = 0, x;
	cin >> n;
	for(long long i = 0; i < n; i++)
	{
		cin >> x;
		if(x % 3 == 0) c0++;
		else if(x % 3 == 1) c1++;
		else c2++;
	}

	c1 -= n / 3;
	c2 -= n / 3;
	c0 -= n / 3;

	long long ans = 0;
	if(c1 > 0) ans += c1;
	if(c2 > 0) ans += c2;
	if(c0 > 0) ans += c0;

	cout << ans;
}