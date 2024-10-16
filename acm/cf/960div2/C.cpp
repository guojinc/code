#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Pair{
    int x, y, l;
    bool operator < (const Pair &a) const
    {
        if (y == 2 && a.y != 2)
        {
            return true;
        }
        if (y != 2 && a.y == 2)
        {
            return false;
        }
        return x > a.x;
    }
};

void solve()
{
    int n;
    cin >> n;
    int arr[n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int l = 1;
    // int b[n + 1] = {0};
    while (l < n)
    {
        int M = 0;
        int cnt[n + 1] = {0};
        int id = l;
        for (int i = l; i <= n; i++)
        {
            cnt[arr[i]]++;
            if (cnt[arr[i]] == 2)
            {
                M = max(M, arr[i]);
                if (id == l)
                {
                    id = i;
                }
            }
            arr[i] = M;
            sum += M;
        }
        l = id;
    }
    cout << sum << endl;
}

signed main()
{
    ios
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}