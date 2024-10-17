#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int arr[n + 1];
    arr[1] = -1;
    arr[n] = -1;
    for (int i = y; i <= x; i++)
    {
        arr[i] = 1;
    }
    int turn = -1;
    for (int i = y - 1; i >= 2; i--)
    {
        arr[i] = turn;
        turn *= -1;
    }
    turn = -1;
    for (int i = x + 1; i <= n - 1; i++)
    {
        arr[i] = turn;
        turn *= -1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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