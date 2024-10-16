#include <bits/stdc++.h>
using namespace std;
int matrix[1010][1010];
int cal[1010][1010];

int main()
{
    int n, m, k, l;
    int ans = 0;
    cin >> n >> m >> k >> l;
    for (int i = 0; i < n; i++)
    {
        // col += matrix[i][0];
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            // if (i == 0)
            // {
            //     row += matrix[0][j];
            // }
        }
    }

    cal[0][0] = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cal[0][0] += matrix[i][j];
            if (cal[0][0] > 0)
                ans += cal[0][0];
            if (cal[0][0] < 0)
                ans -= cal[0][0];
        }
    }

    for (int i = 0; i < n - k + 1; i++)
    {
        int row_duce = 0;
        int row_add = 0;
        for (int j = 0; j < l; j++)
        {
            row_duce += matrix[i][j];
            row_add += matrix[i + k][j];
        }
        cal[0][i + 1] = 0;
        cal[0][i + 1] = cal[0][i] - row_duce + row_add;
        if (cal[0][i + 1] > 0)
        {
            ans += cal[0][i + 1];
        }
        if (cal[0][i + 1] < 0)
        {
            ans -= cal[0][i + 1];
        }
        
    }

    for (int i = 0; i < n - l + 1; i++)
    {
        for (int j = 0; j < m - k + 1; j++)
        {
            int col_duce = 0;
            int col_add = 0;
            for (int x = 0; x < k; x++)
            {
                col_duce += matrix[j][i + x];
                col_add += matrix[j + k][i + x];
            }
            cal[j + 1][i] = 0;
            cal[j + 1][i] = cal[i][j] - col_duce + col_add;
            if (cal[j + 1][i] > 0)
            {
                ans += cal[j + 1][i];
            }
            if (cal[j + 1][i] < 0)
            {
                ans -= cal[j + 1][i];
            }
            
        }
    }
    for (int i = 0; i < n - l + 1; i++)
    {
        for (int j = 0; j < m - k + 1; j++)
        {
            cout << cal[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
}