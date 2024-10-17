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
    vector <int> arr(n + 2, 0);
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr[x] = 1;
        if (i == 1) continue;
        if (arr[x + 1] == 0 && arr[x - 1] == 0)
        {
            ok = true;
        }
    }
    if (ok) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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