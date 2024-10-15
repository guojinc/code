#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(),a.end()
#define bg begin()
#define ed end()
#define mod 998244353
#define mod7 1e9 + 7
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct tree
{
    int l, r;
    int val;
    int lazy;
}t[800005];

void build(int l, int r, int p)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].val = 0;
        t[p].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    t[p].val = 0;
}

void pushdown(int u)
{
    if (t[u].lazy) {
        t[u * 2].val += t[u].lazy;
        t[u * 2 + 1].val += t[u].lazy;
        t[u * 2].lazy += t[u].lazy;
        t[u * 2 + 1].lazy += t[u].lazy;
        t[u].lazy = 0;
    }
}

void pushup(int p)
{
    t[p].val=max(t[p<<1].val,t[p<<1|1].val);
}

void modify(int u, int l, int r, int x = 1)
{
    if(l<=t[u].l && t[u].r<=r){
		t[u].lazy+=x;
		t[u].val+=x;
        // t[u].val = max(t[t[u].l].val, t[t[u].r].val);
		return;
	}

	int mid=(t[u].l+t[u].r)/2;
	// 需要查找孩子节点，要将lazy标记向下传递
	pushdown(u);
	if(l<=mid) modify(u*2,l,r,x);
	if(mid<r) modify(u*2+1,l,r,x);
	// 修改完成后要记得更新父节点的值
	pushup(u);
}

int query(int l, int r, int p)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        return t[p].val;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    int ans = 0;
    pushdown(p);
    if (l <= mid)
    {
        ans = max(ans,query(l, r, p << 1));
    }
    if (r > mid)
    {
        ans = max(ans,query(l, r, p << 1 | 1));
    }
    return ans;
}



void solve()
{
    int n, d, k;
    cin >> n >> d >> k;
    for (int i = 0; i < n * 4; i++)
    {
        t[i].l = 0;
        t[i].r = 0;
        t[i].val = 0;
        t[i].lazy = 0;
    }
    build(1, n, 1);
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        modify(1, l, r);
    }
    int bro = 0;
    int bro_id;
    int mom = 10000000000;
    int mom_id;
    for (int i = 1; i <= n - d + 1; i++)
    {
        int temp = query(i, i + d - 1, 1);
        if (bro < temp)
        {
            bro = temp;
            bro_id = i;
        }
        if (mom > temp)
        {
            mom = temp;
            mom_id = i;
        }
    }
    cout << bro_id << " " << mom_id << endl;
}

signed main()
{
    ios
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}