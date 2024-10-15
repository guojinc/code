#include <bits/stdc++.h>

using namespace std;
int w[105];
map<int, vector<pair<int, int>>> road;
priority_queue<float> pq;
void dfs(int cur, int pre, int n, float &ans)
{
    if (cur == n)
    {
        pq.push(ans);
        return;
    }
    for (auto i : road[cur])
    {
        if (i.first == pre)
        {
            continue;
        }
        float t = ans;
        ans = (ans + w[i.first]) * i.second;
        
        dfs(i.first, cur, n, ans);
        ans -= w[i.first] * i.second;
    }
}

int main()
{
    while (1)
    {
        int n, m;
        if (scanf("%d %d", &n, &m) == EOF)
            break;

        for (int i = 1; i < n; i++)
        {
            scanf("%d", &w[i]);
        }

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            road[a].push_back({b, 1 - c});
            road[b].push_back({a, 1 - c});
        }
        float ans = 0;
        dfs(0, -1, n, ans);
        road.clear();
        printf("%.2f\n", pq.top());
        while(!pq.empty()){
            pq.pop();
        }
    }
}