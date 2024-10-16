#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void solve()
{
    string s;
    cin >> s;
    // cout << "ava" + s << endl;
    if (s == "")
    {
        cout << "Yes" << endl;
        return;
    }
    int pos = 0;
    while (1)
    {
        if (s.substr(pos, 5) == "avava")
        {
            pos += 5;
        }
        else if (s.substr(pos, 3) == "ava")
        {
            pos += 3;
        }
        else if (pos == s.size())
        {
            break;
        }
        else
        {
            cout << "No" << endl;
            return;
        }   
    }
    cout << "Yes" << endl;
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