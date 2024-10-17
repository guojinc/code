#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<string, char> mp;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int len = n;
    string s;
    cin >> s;
    string ss = s;
   
    s = ' ' + s;
    while (n--)
    {
        if (mp.find(s.substr(n, len)) != mp.end())
        {
            cout << mp[s.substr(n, len)];
            continue;
        }
        int cnt_0 = 0;
        int cnt_1 = 0;
        int cnt_win = 0;
        int cnt_lose = 0;
        int i = len - n;
        while (1)
        {
            if (s[i] == '0')
            {
                cnt_0++;
            }
            if (s[i] == '1')
            {
                cnt_1++;
            }
            if (cnt_0 == b)
            {
                cnt_lose++;
                cnt_0 = 0;
                cnt_1 = 0;
            }
            if (cnt_1 == b)
            {
                cnt_win++;
                cnt_0 = 0;
                cnt_1 = 0;
            }
            if (cnt_win == a)
            {
                cout << "1";
                mp[s.substr(n, i - n + 1)] = '1';
                break;
            }
            if (cnt_lose == a)
            {
                cout << "0";
                mp[s.substr(n, len)] = '0';
                break;
            }
            i++;
            if (i == s.size())
            {
                s += ss;
            }
        }
    }

}

signed main()
{
    ios
    solve();   
}