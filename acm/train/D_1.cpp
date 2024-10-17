#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
    int l, r;
    int sum;
    int lazy;
}tree[401000];

int ary[401000];

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
void build(int i, int l, int r)
{
    tree[i] = {l, r, 0, 0};
    if (l == r)
    {
        tree[i].sum = ary[l];
        return;
    }

    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);  
    tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}


void update(int tar, int val, int i)
{
    int l = tree[i].l;
    int r = tree[i].r;
    if (l == r)
    {
        tree[i].sum += val;
        return;
    }
    int mid = (l + r) / 2;

    if (tar <= mid)
    {
        update(tar, val, i * 2);
    }
    else
    {
        update(tar, val, i * 2 + 1);
    }   
    tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}


// void modify(int i, int l, int r, int k)
// {
//     if (tree[i].l >= l && tree[i].r <= r)
//     {
//         tree[i].sum += k * (tree[i].r - tree[i].l + 1);
//         tree[i].lazy += k;
//         return;
//     }

//     int mid = (tree[i].l + tree[i].r) / 2;
//     if (l <= mid)
//     {
//         modify(i * 2, l, r, k);
//     }
//     if (r > mid)
//     {
//         modify(i * 2 + 1, l, r, k);
//     }
//     tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum + tree[i].lazy * (tree[i].r - tree[i].l + 1);
// }

int query(int i, int l, int r)
{
    if (tree[i].l >= l && tree[i].r <= r)
    {
        return tree[i].sum;
    }

    int mid = (tree[i].l + tree[i].r) / 2;
    int res = 0;
    if (l <= mid)
    {
        res += query(i * 2, l, r);
    }
    if (r > mid)
    {
        res += query(i * 2 + 1, l, r);
    }
    return res;
}


int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;    
        scanf("%d", &n);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &ary[j]);
        }
        build(1, 1, n);
        cout << "Case " << i + 1 << ":\n";
        while (1)
        {
            char s[10];
            scanf("%s", s);
            if (strcmp(s, "End") == 0)
            {
                break;
            }
            if (strcmp(s, "Query") == 0)
            {
                int l, r;
                scanf("%d %d", &l, &r);
                printf("%d\n", query(1, l, r));
            }
            else if (strcmp(s, "Add") == 0)
            {
                int i, j;
                scanf("%d %d", &i, &j);
                update(i, j, 1);
            }
            else if (strcmp(s, "Sub") == 0)
            {
                int i, k;
                scanf("%d %d", &i, &k);
                update(i, -k, 1);
            }
            
        }
    }
    
}