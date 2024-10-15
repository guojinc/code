#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string a;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            a += s[i];
        }
        else if (s[i] != s[i - 1])
        {
            a += s[i];
        }
    }
    if (a[0] == '0')
    {
        a = a.substr(1);
    }
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '0')
        {
            ans++;
        }
    }
    cout << ans << endl;
}