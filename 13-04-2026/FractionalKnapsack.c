#include <stdio.h>

struct item
{
    float p;
    float w;
    float r;
    float x;
};

int main()
{
    int n;
    float m;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter max weight: ");
    scanf("%f", &m);

    struct item temp;
    struct item items[50];

    for (int i = 0; i < n; i++)
    {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%f", &items[i].w);

        printf("Enter profit of item %d: ", i + 1);
        scanf("%f", &items[i].p);

        items[i].r = items[i].p / items[i].w;
        items[i].x = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int max = i;

        for (int j = i + 1; j < n; j++)
        {
            if (items[j].r > items[max].r)
            {
                max = j;
            }
        }

        temp = items[i];
        items[i] = items[max];
        items[max] = temp;
    }

    float remain = m;
    float maxprofit = 0;
    int i = 0;

    while (i < n)
    {
        if (items[i].w > remain)
            break;

        items[i].x = 1;
        remain -= items[i].w;
        maxprofit += items[i].p;
        i++;
    }

    if (i < n)
    {
        items[i].x = remain / items[i].w;
        maxprofit += items[i].x * items[i].p;
    }

    printf("Maximum profit which could be obtained is: %.2f\n", maxprofit);

    return 0;
}