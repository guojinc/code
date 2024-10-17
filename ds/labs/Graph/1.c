#include <stdio.h>
#define INF 1000000
#define MaxSize 100

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
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", dist[i]);
    }
    return 0;
}