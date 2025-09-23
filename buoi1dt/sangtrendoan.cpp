#include<bits/stdc++.h>
using namespace std;

long long l, r; 
vector<long long>a(1e6 + 7, 1);

void sang()
{
	for(long long i = l; i <= r; i++)
	{
		for(long long j = max(i * i, (l - r + 1)/ i * i); j <= r; j += i)
		{
			a[j - l] = 0;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> l >> r;
    if(l < 2) l = 2;
    sang();

    for(long long i = l; i <= r; i++)
    {
    	if(a[i - l] == 1) cout << i << " ";
    }

    return 0;
}