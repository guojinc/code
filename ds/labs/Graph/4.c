#include <stdio.h>
#define INF 1000000
#define MaxSize 100

int Matrix[MaxSize][MaxSize];
int Path[MaxSize][MaxSize];

void Floyd(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Path[i][j] = j;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Matrix[i][k] + Matrix[k][j] < Matrix[i][j])
                {
                    Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
                    Path[i][j] = Path[i][k];
                }
            }
        }
    }
}

void PrintPath(int u, int v)
{
    printf("%d\n", u);
    while (u != v)
    {
        u = Path[u][v];
        printf("%d\n", u);
    }

}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &Matrix[i][j]);
        }
    }
    Floyd(N);
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        PrintPath(u, v);
    }
    return 0;
}