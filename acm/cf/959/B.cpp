#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main()
{
    ios
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string t;
        int n;
        cin >> n;
        cin >> s >> t;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && t[i] == '1' || s[i] == '1' && t[i] == '0')
            {
                cout << "YES" << endl;
                break;
            }
            if (s[i] == '0' && t[i] == '1')
            {
                cout << "NO" << endl;
                break;
            }
            if (i == n - 1)
            {
                cout << "YES" << endl;
            }
        }
        // if (s[0] == '0' && t[0] == '1')
        // {
        //     cout << "NO" << endl;
        //     continue;
        // }
        // if (s[0] == '1' && t[0] == '0')
        // {
        //     cout << "YES" << endl;
        //     continue;
        // }
        // if (s[0] == '1' && t[0] == '1')
        // {
        //     cout << "YES" << endl;
        //     continue;
        // }
        // if (s[0] == '0' && t[0] == '0')
        // {
        //     for (int i = 1; i < n; i++)
        //     {
        //         if ((s[i] == '1' && t[i] == '0') || (s[i] == '1' && t[i] == '1'))
        //         {
        //             cout << "YES" << endl;
        //             break;
        //         }
        //         if (s[i] == '0' && t[i] == '0')
        //         {
        //             continue;
        //         }
        //         if (s[i] == '0' && t[i] == '1')
        //         {
        //             cout << "NO" << endl;
        //             break;
        //         }
        //     }
        // }
    }
}