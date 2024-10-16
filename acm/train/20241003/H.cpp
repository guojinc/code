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

void add(int x, int y, vector<umap<int, int>> &group, vector<pii> &student)
{
    group[y][x] = group[y][0];
}

void quit(int x, int y, vector<umap<int, int>> &group, vector<pii> &student)
{
    student[x].second += group[y][0] - group[y][x];
    group[y][x] = -1;
    // cout << group[y][0] << " " << group[y][x] << endl;
    // cout << x << " " << student[x].first << " " << student[x].second << endl;
}

void send(int x, int y, vector<umap<int, int>> &group, vector<pii> &student)
{
    student[x].first++;
    group[y][0]++;
    // cout << y << " " << group[y][0] << endl;
}

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<umap<int, int>> group(n + 1);
    vector<pii> student(m + 1);

    while (s--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            add(x, y, group, student);
        }
        else if (t == 2)
        {
            quit(x, y, group, student);
        }
        else if (t == 3)
        {
            send(x, y, group, student);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : group[i])
        {
            if (j.first != 0 && j.second != -1)
            {
                student[j.first].second += group[i][0] - j.second;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        // cout << student[i].first << " " << student[i].second << endl;
        cout << student[i].second - student[i].first << endl;
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