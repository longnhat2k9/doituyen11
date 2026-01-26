#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, k; cin >> n >> k;
	multiset<long long>s;
	long long x;
	for(long long i = 0; i < k - 1; i++)
	{
		cin >> x;
		s.insert(x);
	}

	for(long long i = k - 1; i < n; i++)
	{
		cin >> x;
		s.insert(x);
		while(s.size() > k) s.erase(s.begin());
		cout << *s.begin() << "\n";
	}

	return 0;
}