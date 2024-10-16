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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int al = 0, ar = n - 1;
    int bl = 0, br = n - 1;
    // while (al <= ar)
    for (int i = 0; i < n - 1; i ++)
    {
        if (a[al] == b[bl] && a[ar] == b[br])
        {
            al++;
            bl++;
        }
        else if (a[al] == b[br] && a[ar] == b[bl])
        {
            al++;
            br--;
        }
        else if ((a[al] != b[bl] && a[al] != b[br]) || (a[ar] != b[bl] && a[ar] != b[br]))
        {
            cout << "Alice" << endl;
            return;
        }

    }
    cout << "Bob" << endl;
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