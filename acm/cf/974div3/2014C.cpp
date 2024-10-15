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
    vector<int> arr(n + 1, 0);
    double cal = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cal += arr[i];
    }
    sort(all(arr));
    int mid = n / 2;
    double average = cal / n;
    if (n <= 2)
    {
        cout << -1 << endl;
        return;
    }
    if (average / 2 > arr[mid + 1])
    {
        cout << 0 << endl;
        return;
    }
    // int ans = ceil((arr[mid + 1] * 2 - average) * n);
    int ans = arr[mid + 1] * 2 * n - cal + 1;
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