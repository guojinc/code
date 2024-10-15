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
    int n, kt, move;
    cin >> n >> kt >> move;
    int k = move % n;
    int m = move / n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        mp[num].push_back(i);
    }
    vector<int> ans(n + 1);
    for (auto &i : mp)
    {
        int key = i.first;
        auto val = i.second;
        int Size = val.size();
        for (int j = 0; j < Size; j++)
        {
            if (Size % 2 == 0)
            {
                if (val[j] > 0 && val[j] <= k && j % 2 == 1)
                {
                    ans[val[j]]++;
                }
                if (j % 2 == 1)
                {
                    ans[val[j]] += m;
                }
            }
            else{
                if (val[j] > 0 && val[j] <= k && j % 2 == 1)
                {
                    ans[val[j]]++;
                }
                if (val[j] > 0 && val[j] <= k && j % 2 == 0 && m % 2 == 1)
                {
                    ans[val[j]]++;
                }
                ans[val[j]] += m / 2;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
        if (i != n)
            cout << " ";
    }
    cout << endl;
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