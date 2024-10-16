#include <stdio.h>

int main()
{
    int m ,n;
    scanf("%d %d",&m, &n);

    int arr[m + n];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int  i = 0; i < n; i++)
    {
        arr[m + i] = arr[i];
    }

    int *arr_shifted = arr + n;
    for (int  i = 0; i < m; i ++)
    {
        printf("%d", arr_shifted[i]);
        if (i != m - 1)
        {
            printf(" ");
        }
    }
}