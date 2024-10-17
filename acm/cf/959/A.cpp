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
        int n, m;
        cin >> n >> m;
        
        int arr[n + 1][m + 1];
        for (int  i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j]; 
            }
        }
        if (n == 1 && m == 1)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            arr[n][i] = arr[0][i];
        }
        for (int i = 1; i <= n; i++)
        {
            arr[i][m] = arr[i][0];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}