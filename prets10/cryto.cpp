#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k; cin >> n >> k;
    vector<long long>a(n);
    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if(k == 1)
    {
        vector<long long>b(n);
        b[0] = a[0];
        long long cnt = 0;
        for(long long i = 1; i < n; i++)
        {
            b[i] = min(a[i - 1], b[i - 1]);
            cnt = max(cnt, a[i] - b[i]);
        }

        cout << cnt << endl;
    }
    else
    {
        long long ans = 0;
        while(k--)
        {
            long long cnt = 0;
            long long mxloca = 0;
            vector<long long>loca(a.size());
            vector<long long>b(a.size());
            loca[0] = 0;
            b[0] = a[0];
            for(long long i = 1; i < a.size(); i++)
            {
                // b[i] = min(a[i - 1], b[i - 1]);
                // cnt = max(cnt, a[i] - b[i]);

                if(a[i - 1] < b[i - 1])
                {
                    b[i] = a[i - 1];
                    loca[i] = i - 1;
                }
                else
                {
                    b[i] = b[i - 1];
                    loca[i] = loca[i - 1];
                }

                if(cnt < a[i] - b[i])
                {
                    cnt = a[i] - b[i];
                    mxloca = i;
                }
            }
            ans += cnt;
            if(cnt == 0) break;
            a.erase(a.begin(), a.begin() + mxloca + 1);
        }
        cout << ans << endl;
    }

    return 0;
}