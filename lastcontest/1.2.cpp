#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

float dis(pair<float, float>a, pair<float, float>b, pair<float, float>m)
{
    // vector
    pair<float, float>ab, am, bm;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;

    am.x = m.x - a.x;
    am.y = m.y - a.y;

    bm.x = m.x - b.x;
    bm.y = m.y - b.y;

    // hinh chieu
    float t = ((am.x * ab.x) + (am.y * ab.y))/((ab.x * ab.x) + (ab.y * ab.y));

    float d;
    if(1.0 >= t && t >= 0.0)
    {
        d = abs(ab.x * am.y - ab.y * am.x) / sqrt(ab.x * ab.x + ab.y * ab.y);
    }
    else if(t < 0.0)
    {
        d = sqrt(am.x * am.x + am.y * am.y);
    }
    else
    {
        d = sqrt(bm.x * bm.x + bm.y * bm.y);
    }

    return d;
}

void cs()
{
    long long n; cin >> n;
    pair<float, float>m; cin >> m.x >> m.y;
    pair<float, float>a, b; cin >> b.x >> b.y;
    pair<float, float>f = b;

    float mx = 1e6;

    for(long long i = 1; i < n; i++)
    {
        a = b;
        cin >> b.x >> b.y;
        mx = min(mx, dis(a, b, m));
    } 

    cout << fixed << setprecision(4) << min(mx, dis(f, b, m));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("i", "r", stdin);
    // freopen("o", "w", stdout);

    cs();
}