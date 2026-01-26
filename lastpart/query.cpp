#include<bits/stdc++.h>
using namespace std;

const long long mxn = 200005;
long long n, q, a[mxn], t[mxn * 4], lz[mxn * 4];

void build(long long id, long long l, long long r)
{
	if(l == r)
	{
		t[id] = a[l];
		return;
	}

	long long m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	t[id] = t[id * 2] + t[id * 2 + 1];
}

void push(long long id, long long l, long long r)
{
	if(lz[id])
	{
		lz[id * 2] += lz[id];
		lz[id * 2 + 1] += lz[id];
		long long m = (r + l) / 2;
		t[id * 2] += lz[id] * (m - l + 1);
		t[id * 2 + 1] += lz[id] * (r - m - 1 + 1);
		lz[id] = 0;
	}
}

void update(long long id, long long l, long long r, long long u, long long v, long long val)
{
	if(v < l || r < u) return;
	if(u <= l && r <= v)
	{
		t[id] += val * (r - l + 1);
		lz[id] += val;
		return;
	}
	long long m = (l + r) / 2;
	push(id, l, r);
	update(id * 2, l, m, u, v, val);
	update(id * 2 + 1, m + 1, r, u, v, val);
	t[id] = t[id * 2] + t[id * 2 + 1];
}

long long get(long long id, long long l, long long r, long long u, long long v)
{
	if(v < l || r < u) return 0;
	if(u <= l && r <= v) return t[id];
	long long m = (l + r) / 2;
	push(id, l, r);
	long long t1 = get(id * 2, l, m, u, v);
	long long t2 = get(id * 2 + 1, m + 1, r, u , v);
	return t1 + t2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
	cin >> q;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
	while(q--)
	{
		long long op, l, r, x;
		cin >> op >> l >> r;
		if(op == 1)
		{
			cin >> x;
			update(1, 1, n, l, r, x);
		}
		else
		{
			cout << get(1, 1, n, l, r) << "\n";
		}
	}

    return 0;
}

/*
8 4
5 6 9 1 2 1 10 15
1 4 7 15
2 3 8
1 2 5 17
2 1 6
*/