#include<bits/stdc++.h>
using namespace std;

long long uoc;
long long n; 
long long cnt = 0;

void cs()
{
	cnt = 0;
	cin >> n;
	cout << n + 2 * (n / 2) + 2 * (n / 3) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while(t--) cs();

	return 0;
}