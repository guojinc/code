#include <stdio.h>
#define INF 10000
#define MaxSize 100

int path[MaxSize];

void Dijkstra(int n, int start, int Matrix[MaxSize][MaxSize], int* dist, int* visited)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    for (int i = 0; i < n; i++)
    {
        int minDist = INF;
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < minDist)
            {
                u = j;
                minDist = dist[j];
            }
        }
        if (u == -1) return;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (visited[v] == 0 && Matrix[u][v] != INF && dist[u] + Matrix[u][v] < dist[v])
            {
                dist[v] = dist[u] + Matrix[u][v];
                path[v] = u;
            }
        }
    }
}

int main()
{
    int Matrix[MaxSize][MaxSize];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &Matrix[i][j]);
        }
    }
    int dist[MaxSize];
    int visited[MaxSize];
    Dijkstra(n, 0, Matrix, dist, visited);

    int u, v;
    scanf("%d %d", &u, &v);
    int D[MaxSize];
    D[0] = u;
    int k = 0;
    while (u != v)
    {
        D[k++] = v;
        v = path[v];
    }
    printf("%d\n", u);
    for (int i = k - 1; i >= 0; i--)
    {
        printf("%d\n", D[i]);
    }
    return 0;
}