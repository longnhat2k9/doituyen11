#include<bits/stdc++.h>
using namespace std;

const long long M = 31622;
vector<long long>a(M + 1, 1);
vector<long long>nto;

void sang()
{
    a[0] = a[1] = 0;
    for(long long i = 2; i <= sqrt(M); i++)
    {
        if(a[i] == 1) for(long long j = i * i; j <= M; j += i)
        {
            a[j] = 0;
        }
    }

    for(long long i = 2; i <= M; i++)
    {
        if(a[i] == 1) nto.push_back(i);
    }
}

vector<long long>lis;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    sang();
    
    long long n; cin >> n;
    long long mu, j, uoc;
    long long x; 
    
    for(long long i = 0; i < n; i++)
    {
        cin >> x;
        mu = 0, j = 0, uoc = 1;
        while(x > 1 && j < nto.size())
        {
            if(nto[j] * nto[j] > x) break;
            while(x % nto[j] == 0 && x > 1)
            {
                mu++;
                x /= nto[j];
            }
            uoc *= mu + 1;
            j++;
            mu = 0;
        }
        if(x > 1) uoc *= 2;
        if(x > 0) uoc *= 2;
        
        auto it = lower_bound(lis.begin(), lis.end(), uoc);
        if(it == lis.end())
        {
            lis.push_back(uoc);
        }
        else 
        {
            *it = uoc;
        }
    }

    cout << lis.size();

    return 0;
}
