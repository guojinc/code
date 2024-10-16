#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int tree[808000];

void Build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &tree[rt]);
        return;
    }
    int m = (l + r) >> 1;
    Build(l, m, rt << 1);
    Build(m + 1, r, rt << 1 | 1);
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

void update(int n, int pos, int val, int l, int r, int rt)
{
    if (l == r)
    {
        tree[rt] = val;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
    {
        update(n, pos, val, l, m, rt << 1);
    }
    else
    {
        update(n, pos, val, m + 1, r, rt << 1 | 1);
    }
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

int Query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return tree[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m)
    {
        ret = max(ret, Query(L, R, l, m, rt << 1));
    }
    if (R > m)
    {
        ret = max(ret, Query(L, R, m + 1, r, rt << 1 | 1));
    }
    return ret;
}

int main()
{
    int n, m;

    while(~scanf("%d %d", &n, &m))
    {
        Build(1, n, 1);
        char op;
        getchar();
        int l, r;
        while (m--)
        {
            scanf("%c", &op);
            scanf("%d %d", &l, &r); 
            if (op == 'Q')
            {
                cout << Query(l, r, 1, n, 1) << endl;
            }
            else if(op == 'U')
            {
                update(n, l, r, 1, n, 1);
            }
            getchar();
        }
    }
}