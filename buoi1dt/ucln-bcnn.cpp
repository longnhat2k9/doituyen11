#include<bits/stdc++.h>
using namespace std;

long long ucln(long long a, long long b)
{
	long long r;
	while(a % b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long a, b; cin >> a >> b;

    cout << "UCLN: " << ucln(a, b) << endl;
    cout << "BCNN: " << a * b / ucln(a, b) << endl;

    return 0;
}