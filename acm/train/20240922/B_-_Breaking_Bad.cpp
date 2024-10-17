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

struct Array
{
    uint arr[5];
    Array()
    {
        for (uint i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    void operator+= (Array a)
    {
        for (uint i = 0; i < 5; i++)
        {
            this->arr[i] += a.arr[i];
        }
    }
    Array operator- (Array a)
    {
        Array b;
        for (uint i = 0; i < 5; i++)
        {
            b.arr[i] = this->arr[i] - a.arr[i];
        }
        return b;
    }

    Array operator>> (int x)
    {
        Array a;
        for (uint i = 0; i < 5; i++)
        {
            a.arr[(i + x) % 5] = arr[i];
        }
        return a;
    }
};


void solve()
{
    int n;
    cin >> n;
    vector<vector<uint>> a(n + 1, vector<uint>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<Array>> dp(n + 1, vector<Array>(n + 1, Array()));
    Array DP = Array();

    for (int i = 1; i <= n; i++)
    {
        dp[1][i].arr[a[1][i]]++;
        DP += dp[1][i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = (DP - dp[i - 1][j]) >> a[i][j];
        }
        DP = Array();
        for (int j = 1; j <= n; j++)
        {
            DP += dp[i][j];
        }
    }
    DP = Array();
    for (int i = 1; i <= n; i++)
    {
        DP += dp[n][i];
    }
    for (int i = 0; i < 5; i++)
    {
        if (DP.arr[i] > 0)
        {
            cout << "Y";
        }
        else
        {
            cout << "N";
        }
    }
    cout << endl;
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