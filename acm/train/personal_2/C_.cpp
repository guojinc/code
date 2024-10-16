#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 998244353;
int maxd = 0;
int rt = 0;
int f[200005];
int ans = 1;
int tmp;
int cnt = 0;
vector<int> graph[200005];

void dfs(int c, int fa, int dis)
{
    f[c] = fa;
    if (dis > maxd) maxd = dis, rt = c;
    for (auto i : graph[c])
    {
        if (i == fa) continue;
        dfs(i, c, dis + 1);
    }
}

void dfs1(int c, int fa, int dis)
{
    if (dis == tmp) cnt++;
    for (auto i : graph[c])
    {
        if (i == fa) continue;
        dfs1(i, c, dis + 1);
    }
}

signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if (n == 1) break;
    }
    dfs(1, 0, 1);
    int l = rt;
    maxd = 0;
    rt = 0;
    dfs(l, 0, 1);
    int r = rt;
    if (maxd % 2)
    {
        int x = r;
        for (int i = 0; i < maxd / 2; i++) x = f[x];
        tmp = maxd / 2;
        cnt = 0;
        for (auto i : graph[x])
        {
            dfs1(i, x, 1);
            ans = ans * (cnt + 1) % mod;
            cnt = 0;
        }

        dfs1(x, 0, 0);
        ans -= 1 + cnt;
    }
    else{
        int x = r;
        for (int i = 0; i < maxd / 2 - 1; i++) x = f[x];
        tmp = maxd / 2 - 1;
        cnt = 0;
        dfs1(x, f[x], 0);
        ans = ans * cnt % mod;
        cnt = 0;
        dfs1(f[x], x, 0);
        ans = ans * cnt % mod;
    }
    cout << ans << endl;
}