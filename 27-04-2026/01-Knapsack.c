#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int knapsack(int n, int m, int w[], int p[])
{
    int i, j;
    int table[n + 1][m + 1];

    for (i = 0; i <= n; i++)
        table[i][0] = 0;

    for (j = 0; j <= m; j++)
        table[0][j] = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (j < w[i - 1])
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = max(
                    table[i - 1][j],
                    p[i - 1] + table[i - 1][j - w[i - 1]]
                );
            }
        }
    }

    return table[n][m];
}

int main()
{
    int n, m;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[n], p[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);

    printf("Maximum Profit = %d\n", knapsack(n, m, w, p));

    return 0;
}