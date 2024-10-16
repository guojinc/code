#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    string s;
    cin >> s;
    int cnt_Y = 0;
    int cnt_N = 0;
    int cnt_ = 0;
    for (int i = 0; i < 5; i++)
    {
        if (s[i] == 'Y')
        {
            cnt_Y++;
        }
        else if (s[i] == 'N')
        {
            cnt_N++;
        }
        else
        {
            cnt_++;
        }
    }
    if (cnt_Y + cnt_ < 4)
    {
        cout << -1 << endl;
        return;
    }
    if (cnt_Y + cnt_ >= 4 && cnt_Y < 4)
    {
        cout << 0 << endl;
        return;
    }
    if (cnt_Y >= 4)
    {
        cout << 1 << endl;
        return;
    }
    cout << -1 << endl;
}


signed main()
{
    ios
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}