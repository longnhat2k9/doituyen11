#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n; cin >> n;
    vector<long long>a(1e6 + 7, 0);

    for(long long i = 0; i < n; i++)
    {
    	long long x; cin >> x;
    	a[x]++;
    }

    // cau a;

    long long cnt = 0;
    for(long long i = 0; i <= 1e6 + 7; i++)
    {
    	cnt += (a[i] > 0);
    }
    cout << cnt << endl;

    // cau b;
    long long mx = a[0], mxn = 0;
    for(long long i = 1; i <= 1e6 + 7; i++)
    {
    	if(a[i] > mx)
    	{
    		mx = a[i];
    		mxn = i;
    	}
    }

    cout << mxn << " " << mx << endl;

    // cau c;
    for(long long i = 1; i <= 1e6 + 7; i++)
    {
    	if(a[i] == 0)
    	{
    		cout << i << endl;
    		break;
    	}
    }

    return 0;
}