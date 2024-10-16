#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> arr(w);
    for (int i = 0; i < w; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    vector<int> t(n * m + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            t[min({k, i, m - i + 1, m - k + 1}) * min({j, n - j + 1, k, n - k + 1})]++;
        }
    }
    int p = t.size() - 1;
    for (int i = 0; i < w; i++)
    {
        while (t[p] == 0)
        {
            p--;
        }
        ans += arr[i] * p;
        t[p]--;
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