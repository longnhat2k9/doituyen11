#include<bits/stdc++.h>
using namespace std;

vector<long long>nto;
const long long M = 1e5;
vector<long long>a(M + 1, 1);

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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    sang();

    long long n; cin >> n;

    vector<long long>uoc(n, 1);
    vector<long long>v(n);
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x; v[i] = x;
        for(auto &y : nto)
        {
            if(y * y > x) break;
            long long cnt = 1;
            while(x % y == 0 && x > 1)
            {
                cnt++;
                x /= y;
            }
            uoc[i] *= cnt;
            if(x <= M && a[x] == 1)
            {
                uoc[i] *= 2;
                x = 1;
            }
            if(x == 1) break;
        }
        if(x > 1) uoc[i] *= 2;
    }

    // // *debug
    // for(auto &x : uoc) cout << x << " ";
    // cout << endl;
    // //

    vector<long long>ans(n, -1);
    
    stack<long long>st;

    for(long long i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && uoc[st.top()] <= uoc[i]) st.pop();
        if(!st.empty()) ans[i] = v[st.top()];
        st.push(i);
    }

    for(auto &x : ans) cout << x << " ";

    return 0;
}
