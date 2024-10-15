#include <iostream>
#include <ios>
using namespace std;
#define int long long

void solve(){
    int m, n, k;
    cin >> m >> n >> k;
    char arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = '-';
        }
    }
    if (k > 7)
    {
        cout << "No" << endl;
        return;
    }
    // if (k == 7)
    // {
    //     if (n > 2 && m > 2)
    //     {
    //         cout << "Yes" << endl;
    //         arr[n][m] = '*';
    //         for (int i = 0; i < m; i++)
    //         {
    //             for (int j = 0; j < n; j++)
    //             {
    //                 cout << arr[i][j];
    //             }
    //             if (i != m - 1) cout << endl;
    //         }
    //     }
    //     else{
    //         cout << "No" << endl;
    //     }
    //     return;
    // }
    // if (k == 6)
    // {
    //     if (min(m, n) >= 2 && max(m, n) > 2)
    //     {
    //         cout << "Yes" << endl;
    //         arr[n][m] = '*';
    //         for (int i = 0; i < m; i++)
    //         {
    //             for (int j = 0; j < n; j++)
    //             {
    //                 cout << arr[i][j];
    //             }
    //             if (i != m - 1) cout << endl;
    //         }
        
    //     }
    //     else{
    //         cout << "Yes" << endl;
    //     }
    // }
    if (n > 2 && m > 2)
    {
        cout << "Yes" << endl;
        arr[1][1] = '*';
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
        return;
    }
    if (min(m, n) == 2 && max(m, n) > 2)
    {
        if (k < 7)
        {
            cout << "Yes" << endl;
            arr[1][1] = '*';
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j];
                }
                    cout << endl;
            }
            return;
        }
        if (k == 7)
        {
            cout << "No" << endl;
            return;
        }
    }
    if (m == 2 && n == 2)
    {
        if (k <= 4)
        {
            cout << "Yes" << endl;
            arr[1][1] = '*';
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j];
                }
                    cout << endl;
            }
            return;
        }
        else{
            cout << "No" << endl;
            return;
        }
    }
    if (min(n, m) == 1 && max(n, m) == 2)
    {
        if (k <= 2)
        {
            cout << "Yes" << endl;
            arr[0][0] = '*';
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j];
                }
                    cout << endl;
            }
            return;
        }
        else{
            cout << "No" << endl;
            return;
        }
    }
    if (m == 1 && n > 2)
    {
        if (k <= 3)
        {
            cout << "Yes" << endl;
            arr[0][1] = '*';
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j];
                }
                    cout << endl;
            }
            return;
        }
        else{
            cout << "No" << endl;
            return;
        }
    }
    if (m > 2 && n == 1)
    {
        if (k <= 3)
        {
            cout << "Yes" << endl;
            arr[1][0] = '*';
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j];
                }
                    cout << endl;
            }
            return;
        }
        else{
            cout << "No" << endl;
            return;
        }
    }
    if (m == n && m == 1)
    {
        if (k == 1)
        {
            cout << "Yes" << endl;
            cout << "*" << endl;
            return;
        }
        else{
            cout << "No" << endl;
            return;
        }
    }
}


signed main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}

