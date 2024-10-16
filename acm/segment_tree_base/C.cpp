#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
int mod = 1000000007;

struct Matrix{
    int a11, a12;
    int a21, a22;
    Matrix operator = (const Matrix &b){
        a11 = b.a11;
        a12 = b.a12;
        a21 = b.a21;
        a22 = b.a22;
        return *this;
    }
    Matrix operator * (const Matrix &b) const{
        Matrix c;
        c.a11 = (1ll * a11 * b.a11 + 1ll * a12 * b.a21) % mod;
        c.a12 = (1ll * a11 * b.a12 + 1ll * a12 * b.a22) % mod;
        c.a21 = (1ll * a21 * b.a11 + 1ll * a22 * b.a21) % mod;
        c.a22 = (1ll * a21 * b.a12 + 1ll * a22 * b.a22) % mod;
        return c;
    }
}tree[404000];

int arr[101000];
int id;
void pushup(int rt)
{
    tree[rt] = tree[rt << 1 | 1] * tree[rt << 1];
}

void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt].a11 = 1;
        scanf("%lld", &tree[rt].a12);
        arr[id++] = tree[rt].a12;
        tree[rt].a21 = 1;
        tree[rt].a22 = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(rt << 1, l, m);
    build(rt << 1 | 1, m + 1, r);
    pushup(rt);
}

Matrix query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return tree[rt];
    }
    int m = (l + r) >> 1;
    Matrix ret;
    ret.a11 = 1;
    ret.a12 = 0;
    ret.a21 = 0;
    ret.a22 = 1;
    if (L <= m)
    {
        ret = ret * query(L, R, l, m, rt << 1);
    }
    if (R > m)
    {
        ret = query(L, R, m + 1, r, rt << 1 | 1) * ret;
    }
    return ret;
}


signed main()
{
    int t;
    while (~scanf("%lld", &t))
    {
        id = 1;
        while (t--)
        {
            int n, m;
            scanf("%lld %lld", &n, &m);
            build(1, 1, n);
            while (m--)
            {
                int l, r;
                scanf("%lld %lld", &l, &r);
                if (r == l)
                {
                    cout << arr[l] << endl;
                }
                else if (r == l + 1)
                {
                    cout << arr[r] << endl;
                }
                else
                {
                    Matrix ans = query(l + 2, r, 1, n, 1);
                    cout << (arr[l] * ans.a12 + arr[l + 1] * ans.a11) % mod << endl;
                }
            }
        }
    }
}