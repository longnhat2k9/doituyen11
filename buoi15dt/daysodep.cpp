#include<bits/stdc++.h>
using namespace std;

vector<long long>nto;

void sang()
{
	vector<int>a(31622 + 1, 1);
	a[0] = a[1] = 0;
	for(long long i = 2; i <= sqrt(a.size()); i++)
	{
		if(a[i] == 1) for(long long j = i * i; j < a.size(); j += i) a[j] = 0;
	}

	for(long long i = 2; i < a.size(); i++) 
	{
		if(a[i] == 1) nto.push_back(i);
	}
}

long long souoc(long long n)
{
	long long uoc = 1, somu = 0, i = 0;
	while(n > 0 && i < nto.size())
	{
        if(nto[i] * nto[i] > n)break;
		while(n % nto[i] == 0 && n > 0)
		{
			somu++;
			n /= nto[i];
		}
		uoc *= (somu + 1);
        i++;
        somu = 0;
	}
    if(n > 1) uoc *= 2;
	return uoc;
}

void cs2(vector<long long> &a, long long &n)
{
    vector<long long>lis;
    long long dp[n];
    memset(dp, 0, sizeof(dp));

    for(long long i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if(it == lis.end()) 
        {
            dp[i] = lis.size();
            lis.push_back(a[i]);
        }
        else
        {
            dp[i] = it - lis.begin();
            *it = a[i];
        }
    }

    cout << lis.size() << endl;
}

void cs() 
{
    long long n; cin >> n;
    vector<long long>a(n, 0);
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        /*
        for(long long j = 1; j <= sqrt(x); j++)
        {
            if(x % j == 0) 
            {
                a[i]++;
                if(x / j != j) a[i]++;
            }
        }
        */
        a[i] = souoc(x);
    }

    cs2(a, n);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

	sang();
    cs();
}
