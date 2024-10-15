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
    string s = "aeiou";
    int cnt = n / 5;
    int m = n % 5;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= cnt; j++)
        {
            cout << s[i];
        }
    }
    for (int i = m; i < 5; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            cout << s[i];
        }
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