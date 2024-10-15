#include <bits/stdc++.h>

using namespace std;

struct node{
    int l, r, sum;
}tree[60060];

int num[10050];
int idx = 0;

void build(int i, int l, int r)
{
    tree[i].l = l;
    tree[i].r = r;
    if (l == r){
        
        scanf("%d",&tree[i].sum);
        num[idx++] = tree[i].sum;
        return;
    }

    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
}

int query(int i, int l, int r)
{
    int L = tree[i].l;
    int R = tree[i].r;
    if (L >= l && R <= r)
        return tree[i].sum;

    int mid = (L + R) / 2;
    int ans = 0;
    if (l <= mid)
        return query(i * 2, l, r);
    if (r > mid)
        return query(i * 2 + 1, l, r);
    return ans;
}

void update(int l, int r, int id, int val, int i)
{
    if (l == r && l == id)
    {
        tree[id].sum = val;
        return;
    }
    int mid = (l + r) / 2;
    if (id <= mid)
        update(l, mid, id, val, 2 * i);
    if (id > mid)
        update(mid + 1, r, id, val, 2 * i + 1);
    tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}

void greedy(int l, int r,int k, int& ans)
{
    int n = r - l + 1;
    int get[n][n];
    int Not[n][n];
    int d = min(k, n / 2);
    get[0][0] = -num[l];
    Not[0][0] = 0;
    for (int i = 1; i <= d; i++)
    {
        get[0][i] = INT_MIN / 2;
        Not[0][i] = INT_MIN / 2;
    }

    for (int i = 1; i < n; ++i) {
            get[i][0] = max(get[i - 1][0], Not[i - 1][0] - num[i + l]);
            for (int j = 1; j <= d; ++j) {
                get[i][j] = max(get[i - 1][j], Not[i - 1][j] - num[i + l]);
                Not[i][j] = max(Not[i - 1][j], get[i - 1][j - 1] + num[i + l]);   
            }
        }
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, Not[n - 1][i]);
    }
}


int main()
{
    int n;
    cin >> n;
    build(1, 1, n);
    int m;
    cin >> m;
    while (m--)
    {
        int op;
        scanf("%d", &op);
        if (op == 0)
        {
            int i, val;
            scanf("%d%d", &i, &val);
            num[i - 1] = val;
            // update(1, n, i, val, 1);
        }
        else
        {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            int ans = 0;
            greedy(l - 1, r - 1, k, ans);



            cout << ans << endl;
        }
    }
}