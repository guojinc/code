#include <cstdio>
#include <iostream>
#include <unordered_map>
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
const int N = 3E4 + 10;
struct node {
	int l, r;
	ll val;
}t[N << 5];
int root[N], ind;
int build(int a, int c, int tl, int tr, int p) {
	int x = ++ind; t[x] = t[p];
	t[x].val += c;
	if (tl == tr) return x;
	int mid = tl + tr >> 1;
	if (a <= mid) t[x].l = build(a, c, tl, mid, t[p].l);
	else t[x].r = build(a, c, mid + 1, tr, t[p].r);
	return x;
}
ll ask(int l, int r, int tl, int tr, int x) {
	if (l <= tl && r >= tr) return t[x].val;
	int mid = tl + tr >> 1;
	ll res = 0;
	if (l <= mid) res = ask(l, r, tl, mid, t[x].l);
	if (r > mid) res += ask(l, r, mid + 1, tr, t[x].r);
	return res;
}
int main()
{
	int T; 
    cin >> T;
	while (T--) {
		ind = 0;

		unordered_map<int, int> mp;
		int n; scanf("%d", &n);
		rep(i, n) {
			int x; scanf("%d", &x);
			root[i] = build(i, x, 1, n, root[i - 1]);
			if (mp.count(x)) root[i] = build(mp[x], -x, 1, n, root[i]);
			mp[x] = i;
		}

		int m; scanf("%d", &m);
		rep(i, m) {
			int l, r; scanf("%d %d", &l, &r);
			printf("%lld\n", ask(l, r, 1, n, root[r]));
		}
	}
	return 0;
}
