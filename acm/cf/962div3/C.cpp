#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void add(map <char, int> mp, map <char, int> &mp1, char c)
{
    mp = mp1;
    mp[c]++;
}

int count(map <char, int> &mp, map <char, int> &mp1)
{
    int cnt = 0;
    char c = 'a';
    for (int i = 0; i < 26; i++, c++)
    {
        cnt += abs(mp[c] - mp1[c]);
    }
    return cnt / 2;
}

map<char, int> reduce(map <char, int> &mp, map <char, int> &mp1)
{
    map <char, int> mp2;
    char c = 'a';
    for (int i = 0; i < 26; i++, c++)
    {
        mp2[c] = abs(mp[c] - mp1[c]);
    }
    return mp2;
}

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<map <char, int>> mp1(n + 1);
    vector<map <char, int>> mp2(n + 1);
    string s1;
    s1 = ' ' + s1;
    cin >> s1;
    mp1[0] = {};
    for (int i = 1; i <= n; i++)
    {
        add(mp1[i], mp1[i - 1], s1[i]);
    }
    string s2;
    cin >> s2;
    s2 = ' ' + s2;
    mp2[0] = {};
    for (int i = 1; i <= n; i++)
    {
        add(mp2[i], mp2[i - 1], s2[i]);
    }
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        auto mpl = reduce(mp1[r], mp1[l]);
        auto mpr = reduce(mp2[r], mp2[l]);
        int cnt = count(mpl, mpr);
        cout << cnt << endl;
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