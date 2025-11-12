#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n;
    vector<long long>a(n + 1, 0), s(n + 1, 0), f(n + 1, 0), g(n + 1, 0);
    deque<long long>dq; dq.push_back(0);
    for(long long i = 1; i <= n; i++) 
    {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    cin >> k;

    for(long long i = 1; i <= n; i++)
    {
        g[i] = f[i - 1];
        while (!dq.empty() && dq.front() < i - k) 
        {
            dq.pop_front();
        }
        f[i] = max(g[i], s[i] + (g[dq.front()] - s[dq.front()]));
        
        while(!dq.empty())
        {
            if(g[i] - s[i] >= g[dq.back()] - s[dq.back()])
            {
                dq.pop_back();
            }
            else 
            {
                break;
            }
        }
        dq.push_back(i);
    }

    cout << f[n];

    return 0;
}