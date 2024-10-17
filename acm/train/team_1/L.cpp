#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> road;
int road[10050][10050];
int tour[100050];
map<int, pair<int, int>> gate; 

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {         
                road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
            }
        }
    }
}

int min(int j, vector<int> open)
{
    int ret = 100000;
    for (auto i : open)
    {
        ret = min(road[j][i], ret);
    }
    return ret * tour[j];
}

void print_floyd(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << road[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            road[i][j] = 1000000;
        }
    }
    // road.resize(n + 1);
    // road[0] = (vector<int>(n + 1, 1000000));
    for (int i = 1; i <= n; i++)
    {
        // road[i] = (vector<int>(n + 1, 1000000));
        cin >> tour[i];
        road[i][i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        gate[x] = {y, z};
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        road[x][y] = z;
        road[y][x] = z;
    }
    floyd(n);
    // print_floyd(n);
    for (int i = 1; i <= t; i++)
    {
        int ans = 0;
        vector<int> open;
        for (auto it : gate)
        {
            if (i >= it.second.first && i <= it.second.second)
            {
                open.push_back(it.first);
            }
        }
        for (int j = 1; j <= n; j++)
        {
            ans += min(j, open);
        }
        cout << ans << endl;
    }
}