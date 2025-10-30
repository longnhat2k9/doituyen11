#include<bits/stdc++.h>
using namespace std;

const long long M = 1e6 + 7;
long long n, k, d[M], b[M];
// vector<pair<long long, long long>>a;
long long sum = 0, mxsum = -1e18;

void cs3(long long j)
{
    for(int i = 0; i <= 1; i++)
    {
        if(i == 1 && d[j - 1] == 1 && d[j - 2] == 1) {}
        else
        {
            d[j] = i;
            sum += d[j] * b[j];
            if(j == n + 1) mxsum = max(mxsum, sum);
            else
            {
                cs3(j + 1);
            }
            sum -= d[j] * b[j];
        }
    }
}

void cs4(long long j)
{
    for(int i = 0; i <= 1; i++)
    {
        if(i == 1 && d[j - 1] == 1) {}
        else
        {
            d[j] = i;
            sum += d[j] * b[j];
            if(j == n + 1) mxsum = max(mxsum, sum);
            else
            {
                cs4(j + 1);
            }
            sum -= d[j] * b[j];
        }
    }
}

// void cs1()
// {
//     for(auto &x : a)
//     {
//         if(d[x.second - 1] == 0 && d[x.second + 1] == 0)
//         {
//             d[x.second] = 1;
//             sum += x.first;
//         }
//     }
//     cout << sum;
// }

// void cs2()
// {
//     for(auto &x : a)
//     {
//         if((d[x.second - 1] == 1 && d[x.second - 2] == 1) || 
//         (d[x.second - 1] == 1 && d[x.second + 1] == 1) ||
//         (d[x.second + 1] == 1 && d[x.second + 2] == 1)) {}
//         else
//         {
//             d[x.second] = 1;
//             sum += x.first;
//         }
//     }
//     cout << sum;
// }

// bool cmp(pair<long long, long long>x, pair<long long, long long>y)
// {
//     return x.first > y.first;
// }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n; memset(d, 0, sizeof(d));
    for(long long i = 2; i <= n + 1; i++)
    {
        cin >> b[i];
        // a.push_back({b[i], i});
    }
    cin >> k;

    if(k == 2) 
    {
        cs3(2);
        cout << mxsum;
        return 0;
    }
    else
    {
        cs4(2);
        cout << mxsum;
        return 0;
    }

    // sort(a.begin(), a.end(), cmp);    

    // if(k == 1) cs1();
    // else cs2();

    return 0;
}