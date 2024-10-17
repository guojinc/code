#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int a;
    cin >> a;
    if (a <= 101)
    {
        cout << "NO" << endl;
        return;
    }
    else{
        if (a < 1000)
        {
            int t = a / 10;
            int m = a % 10;
            if (t != 10 || m <= 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else{
            int t = a / 100;
            int m = a % 100;
            if (t != 10 || m <= 9)
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (a == 10000)
        {
            cout << "NO" << endl;
        }
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