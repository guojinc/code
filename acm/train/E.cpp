#include <iostream>

using namespace std;

typedef long long ll;

int trees[600010];

void pushup(int i)
{
    trees[i] = trees[i * 2] + trees[i * 2 + 1];
}

void build(int i, int l, int r)
{
    if (l == r)
    {
        trees[i] = 1;
        return;
    }

    int mid = (l + r) / 2;

    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    pushup(i);

}

void update(int k, int i, int l, int r)
{
    if (l == r)
    {
        trees[i] = 0;
        return;
    }

    int mid = (l + r) / 2;  
    if (k <= mid)
    {
        update(k, i * 2, l, mid);
    }
    else
    {
        update(k, i * 2 + 1, mid + 1, r);
    }
    pushup(i);
}

int query(int k, int i, int l, int r)
{
    int ans = 0;

    int mid = (l + r) / 2;
    if (l == r)
    {
        return l;
    }

    if (trees[i * 2] >= k)
    {
        ans = query(k, i * 2, l, mid);
    }
    else
    {
        ans = query(k - trees[i * 2], i * 2 + 1, mid + 1, r);
    }
    return ans;
}

int main()
{
    int t;
    int Case = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case " << Case++ << ": ";
        ll ans = 0;
        int n, k;
        cin >> n >> k;
        build(1, 1, n);
        while (k--)
        {
            int kt;
            cin >> kt;
            int temp = query(kt, 1, 1, n);
            update(temp, 1, 1, n);
            ans += temp;
        }
        cout << ans << "\n";
    }
}
