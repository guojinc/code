#include <iostream>
#include <ios>
#include <algorithm>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MaxN = 100050;

struct SegmentTree {
    int l;
    int r;
    int lm;
    int rm;
    int cm;
} tree[MaxN << 2];

int arr[MaxN];

void pushup(int rt)
{
    tree[rt].lm = tree[rt << 1].lm;
    tree[rt].rm = tree[rt << 1 | 1].rm;
    tree[rt].cm = max(tree[rt << 1].cm, tree[rt << 1 | 1].cm);
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (arr[mid] < arr[mid + 1])
    {
        if (tree[rt << 1].lm == mid - tree[rt].l + 1)
        {
            tree[rt].lm += tree[rt << 1 | 1].lm;
        }
        if (tree[rt << 1 | 1].rm == tree[rt].r - mid)
        {
            tree[rt].rm += tree[rt << 1].rm;
        }
        tree[rt].cm = max(tree[rt].cm, tree[rt << 1].rm + tree[rt << 1 | 1].lm);
    }
}

void build(int rt, int l, int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r)
    {
        tree[rt].lm = tree[rt].rm = tree[rt].cm = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(rt << 1, l, m);
    build(rt << 1 | 1, m + 1, r);
    pushup(rt);
}

void update(int rt, int pos, int val)
{
    if (tree[rt].l == tree[rt].r)
    {
        arr[pos] = val;
        return;
    }
    int m = (tree[rt].l + tree[rt].r) >> 1;
    if (pos <= m)
    {
        update(rt << 1, pos, val);
    }
    else
    {
        update(rt << 1 | 1, pos, val);
    }
    pushup(rt);
}

int query(int rt, int ql, int qr)
{
    if (ql <= tree[rt].l && tree[rt].r <= qr)
    {
        return tree[rt].cm;
    }

    int m = (tree[rt].l + tree[rt].r) >> 1;
    int ret = 0;
    if (ql <= m)
    {
        ret = max(ret, query(rt << 1, ql, qr));
    }
    if (m < qr)
    {
        ret = max(ret, query(rt << 1 | 1, ql, qr));
    }
    if (arr[m] < arr[m + 1])
    {
        ret = max(ret, min(m - ql + 1, tree[rt << 1].rm) + min(qr - m, tree[rt << 1 | 1].lm));
    }
    return ret;
}

signed main()
{
    ios
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        build(1, 1, n);
        while (m--)
        {
            char op[3];
            int x, y;
            cin >> op >> x >> y;
            if (op[0] == 'U')
            {
                update(1, x + 1, y);
            }
            else
            {
                cout << query(1, x + 1, y + 1) << endl;
            }
        }
    }
}