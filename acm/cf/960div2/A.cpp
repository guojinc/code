#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    vector <int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin() + 1, arr.end(), greater<int>());
    int max = arr[1];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == max)
        {
            cnt++;
        }
        if (arr[i] != max)
        {
            max = arr[i];
            if (cnt % 2 == 1)
            {
                cout << "YES" << endl;
                break;
            }
            cnt = 1;
        }

        if (i == n)
        {
            if (n % 2 == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
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