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

// int Map[1 << 20];

void backtrack(int n, int current, int pos, const vector<int>& a, int& cnt)
{
    if (pos == -1)
    {
        cnt += a[current];
        return;
    }
    // if (Map[current] != 0)
    // {
    //     cnt += Map[current];
    //     return;
    // }
    // int k = cnt;
    backtrack(n, current, pos - 1, a, cnt);
    // if (a[current] != 0 && Map[current] == 0)
    // {
    //     Map[current] = cnt - k;
    // }

    if (n & (1 << pos))
    {
        int temp = current & ~(1 << pos);
        // if (Map[temp] != 0)
        // {
        //     cnt += Map[temp];
        //     return;
        // }
        // k = cnt;
        backtrack(n, temp, pos - 1, a, cnt);
        // if (a[temp] != 0 && Map[temp] == 0)
        //     Map[temp] = cnt - k;
    }
}

// int highbitcount[1 << 20];

struct node{
    int id;
    int num;
    struct node* left;
    struct node* right;
};


void build(node* root, int pos, int id, vector<int>& a)
{
    if (pos == -1)
    {
        root->id = id;
        if (id <= 1e6)
            root->num = a[id];
            // cout << " " << a[id] << endl;
        return;
    }
    int temp = id & ~(1 << pos);
    root->id = id;
    root->left = new node();
    root->right = new node();
    build(root->left, pos - 1, temp, a);
    build(root->right, pos - 1, id, a);
    root->num = root->left->num + root->right->num;

}

int position(int n, int pos)
{
    return (n & (1 << pos));
}

int query(node* root, int n, int pos)
{
    if (root->id == n)
    {
        return root->num;
    }
    if (position(n, pos) == 0)
    {
        return query(root->left, n, pos - 1);
    }
    else
    {
        return query(root->right, n, pos - 1);
    }
}

int highestBitZero(int x) {
    if (x == 0) return 0;
    int highestBit = 1 << (31 - __builtin_clz(x));
    return x & ~highestBit;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(1e6 + 1, 0);


    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    
    // for (int i = 1; i < n; i++)
    // {
    //     a[i]++;
    // }

    int ans = 0;

    node* root = new node();
    build(root, 21, (1 << 22) - 1, a);

    for (int i = 1; i <= 1e6; i++)
    {
        int cnt = 0;
        if (a[i] == 0)
            continue;
        // int c = highbitcount[i];
        // backtrack(i, i, c, a, cnt);
        int t = i;
        while (t != 0)
        {
            cnt += query(root, t, 21);
            t = highestBitZero(t);
        }
        // ans += (cnt - a[i]) * a[i];
        ans += cnt * a[i];
        // cout << cnt << " ";
    }

    cout << ans << endl;
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