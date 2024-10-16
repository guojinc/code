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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> all;
    int visit[n + 1];
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
        {
            vector<int> s;
            s.push_back(i);
            visit[i] = 1;
            int j = a[i];
            while (visit[j] == 0)
            {
                s.push_back(j);
                visit[j] = 1;
                j = a[j];
            }
            all.push_back(s);
        }
    }

    if (all.size() > 1)
    {
        cout << n << endl;
        cout << all[0].size() << endl;
        for (auto i : all[0])
        {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << n - 2 << endl;
        // cout << n - 1 << endl;
        int k = 0;
        int id = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                id = i;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(1);
        id = 1;//
        ans.push_back(id);
        k++;
        while (1)
        {
            if (a[id] > a[a[id]])
            {
                break;
            }
            ans.push_back(a[id]);
            id = a[id];
            k++;
        }
        ans.push_back(a[id]);
        k++;
        if (n == 2)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            return;
        }
        cout << k << endl;
        sort(ans.begin() + 1, ans.end());
        for (int i = 1; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }


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