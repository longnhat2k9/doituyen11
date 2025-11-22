#include<bits/stdc++.h>
using namespace std;

long long m, n; 
vector<long long>a(1, 0);
long long cnt = 0;

void exp(long long dem, long long tich)
{
    if(dem == 0 || tich > m) return;
    if(dem % 2 == 0) cnt -= m / tich;
    else cnt += m / tich;
    // cout << dem << " " << tich << " " << cnt << endl;
}

void cs(long long j, long long dem, long long tich)
{
    for(long long i = 0; i <= 1; i++)
    {
        if(i == 0 && j < n) cs(j + 1, dem, tich);
        else if(i == 0 && j == n) exp(dem, tich);
        else
        {
            if(tich > m / a[j]) return;
            if(j < n) cs(j + 1, dem + 1, tich * a[j]);
            else exp(dem + 1, tich * a[j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    unordered_set<long long>s;
    for(long long i = 1; i <= n; i++) 
    {
        long long x; cin >> x;
        s.insert(x);
    }

    for(auto &x : s) a.push_back(x);
    n = s.size();
    
    cs(1, 0, 1);

    cout << cnt << endl;
}
