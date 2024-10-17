#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n, maxd, l, r, tmp, cnt, ans = 1;
int fa[200005];
vector<int> g[200005];

void dfs(int x, int f, int st){//找直径
    fa[x] = f;
    if (st > maxd) maxd = st, tmp = x;
    for (int i = 0; i < g[x].size(); i++){
        int v = g[x][i];
        if (v == f) continue;
        dfs(v, x, st + 1);
    }
}

void dfs1(int x, int f, int st){//计算 cnt
    if (st == tmp) cnt++;
    for (int i = 0; i < g[x].size(); i++){
        int v = g[x][i];
        if (v == f) continue;
        dfs1(v, x, st + 1);
    }
}

signed main(){
    cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 1);//跑两边 dfs 找树的直径
    l = tmp, tmp = maxd = 0;
    dfs(l, 0, 1);//跑完这次 dfs maxd 就已经是直径长度了
    r = tmp;
    if (maxd % 2){//分奇偶讨论
        int x = r;
        for (int i = 1; i <= maxd / 2; i++) x = fa[x];//还原中心
        tmp = maxd / 2;//这里可以模拟一下理解
        for (int i = 0; i < g[x].size(); i++, cnt = 0){
            dfs1(g[x][i], x, 1);//求这一个子树下有多少个节点满足要求
            ans = ans * (cnt + 1) % mod;//乘法原理
        }
        dfs1(x, 0, 0);//处理 cnt 的和
        ans -= cnt + 1;//特判掉不可能的情况
    }
    else{
        int x = r;
        for (int i = 1; i <= maxd / 2 - 1; i++) x = fa[x];//还原中心（左边或右边的节点）
        tmp = maxd / 2 - 1, cnt = 0;
        dfs1(x, fa[x], 0);//这里 fa[x] 就是这条边上的另一个点
        ans = ans * cnt % mod, cnt = 0;//计算贡献
        dfs1(fa[x], x, 0);
        ans = ans * cnt % mod;
    }
    cout << ans;
    return 0;
}