#include <bits/stdc++.h>
using namespace std;

long long s; 
long long a[6000], f[6000], sum = 0, cnt = 0;

void cs(int j, int n, vector<long long>&t)
{
    for(long long i = 0; i <= 1; i++)
    {
        f[j] = i;
        if(i == 1) sum += a[j];
        if(sum < s) 
        {
            if(j == n) t.push_back(sum);
            if(j < n) cs(j + 1, n, t);
        }
        else if(sum == s) cnt++;
        if(i == 1) sum -= a[j];
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    long long n;
    memset(f, 0, sizeof(f));
    cin >> n >> s;
    for(long long i = 0; i < n; i++) cin >> a[i];
    vector<long long>t1, t2;
    cs(0, n / 2 - 1, t1);
    cs(n / 2, n - 1, t2);

    sort(t1.begin(), t1.end());
    for(auto &x : t2)
    {
        cnt += upper_bound(t1.begin(), t1.end(), s - x) - lower_bound(t1.begin(), t1.end(), s - x);
    }
    cout << cnt % 123456789 << endl;

    return 0;
}
