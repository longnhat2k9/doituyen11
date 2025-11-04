#include<bits/stdc++.h>
using namespace std;

long long conv2(long long n)
{
    long long sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long conv1(long long a, long long b) 
{
    long long sum = 0;
    for(long long i = a; i <= b; i++) sum += conv2(i);
    return sum;
}

void cs()
{
    long long a, b; cin >> a >> b;
    long long sum = conv1(a, b);
    while(sum > 9) sum = conv2(sum);
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long t; cin >> t;
    while(t--) cs();

    return 0;
}