#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    arr[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    vector<int> l, r;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L') l.push_back(i + 1);
        else r.push_back(i + 1);
    }
    if (l.size() == 0 || r.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    
    reverse(r.begin(), r.end());
    if (l[0] > r[0])
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0, len = min(l.size(), r.size()); i < len; i++)
    {
        if (r[i] < l[i]) break;
        ans += arr[r[i]] - arr[l[i] - 1];
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