#include <stdio.h>
#define INF 1000000
#define MaxSize 100

void Floyd(int n, int Matrix[MaxSize][MaxSize])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Matrix[i][k] + Matrix[k][j] < Matrix[i][j])
                {
                    Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
                }
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
    Floyd(n, Matrix);

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", Matrix[u][v]);
    }



    return 0;
}