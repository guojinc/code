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
    int n, k;
    cin >> n >> k;
    if (n % 2)
    {
        if ((k + 1) / 2 % 2)
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        return;
    }
    if (k / 2 % 2)
    {
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    
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