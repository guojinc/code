#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, t;
    cin >> n >> t;
    string s1;
    string s2;
    cin >> s1 >> s2;
    int arr1[n + 1][30];
    int arr2[n + 1][30];
    for (int i = 0; i < 26; i++)
    {
        arr1[0][i] = 0;
        arr2[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            arr1[i][j] = arr1[i - 1][j];
            arr2[i][j] = arr2[i - 1][j];
        }
        arr1[i][s1[i - 1] - 'a']++;
        arr2[i][s2[i - 1] - 'a']++;
    }
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        int cnt = 0;
        int a[30];
        int b[30];
        for (int i = 0; i < 26; i++)
        {
            a[i] = arr1[r][i] - arr1[l][i];
            b[i] = arr2[r][i] - arr2[l][i];
        }
        for (int i = 0; i < 26; i++)
        {
            cnt += abs(a[i] - b[i]);
        }
        cout << cnt / 2 << endl;
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