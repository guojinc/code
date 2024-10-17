#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define mod 998244353
#define mod7 1e9 + 7
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int l, r, L, R;
    cin >> l >> r;
    cin >> L >> R;
    
    if (r < L || R < l)
    {
        cout << 1 << endl;
        return;
    }
    if (l == L && r == R)
    {
        cout << R - L << endl;
        return;
    }
    if ((l < L && R < r) || (L < l && r < R))
    {
        if ((l < L && R < r))
        {
            cout << R - L + 2 << endl;
            return;
        }
        else{
            cout << r - l + 2 << endl;
            return;
        }
    }
    if ((l <= L && R < r) || (l < L && R <= r) || (L <= l && r < R) || (L < l && r <= R))
    {
        if ((l <= L && R < r) || (l < L && R <= r))
        {
            cout << R - L + 1 << endl;
            return;
        }
        else 
        {
            cout << r - l + 1 << endl;
            return;
        }
    }

    if (l < L && L <= r && r < R)
    {
        cout << r - L + 2 << endl;
        return;
    }
    if (L < l && l <= R && R < r)
    {
        cout << R - l + 2 << endl;
        return;
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