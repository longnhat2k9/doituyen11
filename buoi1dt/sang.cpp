#include<bits/stdc++.h>
using namespace std;

vector<int>a(1e6 + 7, 1);

void sang(long long n)
{
	a[0] = a[1] = 0;
	for(long long i = 2; i <= sqrt(n); i++)
	{
		for(long long j = i * i; j <= n; j += i)
		{
			a[j] = 0;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n; cin >> n;
    sang(n);

    for(long long i = 2; i <= n; i++)
    {
    	if(a[i]) cout << i << " ";
    }

    return 0;
}