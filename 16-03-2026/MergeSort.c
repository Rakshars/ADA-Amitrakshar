#include <stdio.h>

int main()
{
    int a[20], b[20];
    int low, high, mid;
    int i, j, k;

    printf("Enter LOW: ");
    scanf("%d", &low);

    printf("Enter HIGH: ");
    scanf("%d", &high);

    mid = (low + high) / 2;

    printf("Enter the values of Array 1 (sorted):\n");
    for(i = low; i <= mid; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the values of Array 2 (sorted):\n");
    for(i = mid + 1; i <= high; i++)
    {
        scanf("%d", &a[i]);
    }

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    printf("\nMerged Array:\n");

    for(k = low; k <= high; k++)
    {
        printf("%d ", b[k]);
    }

    printf("\n");

    return 0;
}
