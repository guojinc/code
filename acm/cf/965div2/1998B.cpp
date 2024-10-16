#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pair<signed, signed> pii
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";  
    }
    cout << arr[0] << endl;
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