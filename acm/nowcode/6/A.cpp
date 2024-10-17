#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
    int pa;
    vector <int> son;
    int val;
    int cnt0;
    int cnt1;
    double rate;
};

void dfs(vector <Node>& g, int now)
{
    g[now].rate = 0;
    if (g[now].son.size() == 0)
    {
        if (g[now].val == 0)
        {
            g[now].cnt0 = 1;
            g[now].cnt1 = 0;
        }
        else
        {
            g[now].cnt0 = 0;
            g[now].cnt1 = 1;
        }
        return;
    }
    for (auto i : g[now].son)
    {
        dfs(g, i);
        g[now].cnt0 += g[i].cnt0;
        g[now].cnt1 += g[i].cnt1;
        double rate = ((double)g[i].cnt1 + g[now].val) / (g[i].cnt0 + g[i].cnt1 + 1);
        g[now].rate = max(g[now].rate, rate);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector <Node> g(n + 1);
    g[1].pa = 0;
    g[1].val = 0;
    for (int i = 1; i < n; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        g[a].son.push_back(b);
        g[b].pa = a;
        g[b].val = x;
    }
    dfs(g, 1);
    queue <tuple<int, string>> q;
    int turn = 0;
    q.push({1, ""});
    double ans = 0;
    while (q.size() != 0)
    {
        auto [now, s] = q.front();
        if (g[now].son.size() == 0)
        {
            double rate = 0;    
            int cnt0 = 0;
            int cnt1 = 0;
            if (s[0] == '0') 
            {
                cout << 0.00000000 << endl;
                return;
            }
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '0')
                {
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
                if (s[i] == '0')
                {
                    rate = (double)cnt1 / (cnt0 + cnt1);
                    ans = max(ans, rate);
                }
            }
            rate = (double)cnt1 / (cnt1 + cnt0);
            ans = max(ans, rate);
        }
        if (turn == 0)
        {
            turn = 1;
            q.pop();
            double rate = 0;
            for (auto i : g[now].son)
            {
                if (g[i].rate > rate)
                {
                    rate = g[i].rate;
                }
            }
            for (auto i : g[now].son)
            {
                if (g[i].rate == rate)
                {
                    if (g[i].val == 0)
                    {
                        s.push_back('0');
                    }
                    else{
                        s.push_back('1');
                    }
                    q.push({i, s});
                }
            }
        }
        else
        {
            turn = 0;
            q.pop();
            double rate = 1;
            for (auto i : g[now].son)
            {
                if (g[i].rate < rate)
                {
                    rate = g[i].rate;
                }
            }
            for (auto i : g[now].son)
            {
                if (g[i].rate == rate)
                {
                    if (g[i].val == 0)
                    {
                        s.push_back('0');
                    }
                    else
                    {
                        s.push_back('1');
                    }
                    q.push({i, s});
                }
            }
        }
    }
    cout << fixed << setprecision(9) << ans << endl;
}


signed main()
{
    ios
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}