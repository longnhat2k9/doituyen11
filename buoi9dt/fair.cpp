#include <bits/stdc++.h>
using namespace std;

long long n, s; 
long long a[6000], f[6000], sum = 0, cnt = 0;

void cs(int j)
{
    for(long long i = 0; i <= 1; i++)
    {
        f[j] = i;
        if(i == 1) sum += a[j];
        if(sum < s && j < n) cs(j + 1);
        else if(sum == s) cnt++;
        if(i == 1) sum -= a[j];
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    memset(f, 0, sizeof(f));
    cin >> n >> s;
    for(long long i = 0; i < n; i++) cin >> a[i];
    cs(0);
    cout << cnt;

    return 0;
}
