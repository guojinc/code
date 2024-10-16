#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define uint unsigned long long
#define pii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(),a.end()
#define bg begin()
// #define push_back emplace_back
// #define ed end()
#define mod 998244353
#define mod7 1e9 + 7
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct edge {
  int v, w;
};

struct node {
  int dis, u;

  bool operator>(const node& a) const { return dis > a.dis; }
};
const int maxn = 1e5 + 105;

vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node> > q;

inline void read(int& a)
{
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	a = s * w;
}


void dijkstra(int n, int s) {
    memset(dis, 0x3f3f3f, sizeof(int) * (n + 1));
    memset(vis, 0, sizeof(int) * (n + 1));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u]) {
        int v = ed.v, w = ed.w;
        if (dis[v] > dis[u] + w) {
            dis[v] = dis[u] + w;
            q.push({dis[v], v});
        }
        }
    }
}

void solve()
{
    int n, m, q;
    read(n);
    read(m);
    read(q);
    map<int, vector<int>> mp;
    map<int, vector<int>, greater<int>> person;
    for (int i = 1; i <= n; i++)
    {
        int num;
        read(num);
        mp[num].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        read(u);
        read(v);
        e[u].push_back({v, 1});
        e[v].push_back({u, 1});
    }
    vector<pii> people(q);
    for (int i = 0; i < q; i++)
    {
        read(people[i].first);
        read(people[i].second);
        person[people[i].second].push_back(i);
    }
    vector<int> ans(q, 0x3f3f3f);
    int start = 1e5 + 1;
    for (auto N : mp)
    {
        int key = N.first;
        auto val = N.second;
        for (int i = 0; i < val.size(); i++)
        {
            e[start].push_back({val[i], 0});
        }
        dijkstra(maxn, start);
        for (auto P : person)
        {
            if (P.first < key)
            {
                break;
            }
            auto per = P.second;
            for (auto j : per)
            {
                ans[j] = min(ans[j], dis[people[j].first]);
            }
        }
        start++;
    }
    for (int i = 0; i < q; i++)
    {
        if (ans[i] == 0x3f3f3f)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans[i] << endl;
        }
    }
}

signed main()
{
    ios
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}