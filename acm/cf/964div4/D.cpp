
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    string s, t;
    cin >> s >> t;
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < t.size(); i++)
    {
        while (j < s.size())
        {
            if (s[j] == '?')
            {
                s[j] = t[i];
                j++;
                cnt++;
                break;
            }
            if (s[j] == t[i])
            {
                j++;
                cnt++;
                break;
            }
            j++;
        }
    }
    if (cnt == t.size())
    {
        for (int i = j; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                s[i] = 'a';
            }
        }
        cout << "Yes" << endl << s << endl;
    }
    else
    {
        cout << "No" << endl;
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