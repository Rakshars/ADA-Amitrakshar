#include <stdio.h>

#define SIZE 5

int a[SIZE], max, pos, n;
char dir[SIZE];

void print()
{
    for (int i=0; i<n; i++)
    {
        printf("%d(%c) ", a[i], dir[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter n value: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        a[i] = i+1;
        dir[i] = 'L';
    }

    print();

    while (1)
    {
        max = -1;
        pos = -1;

        for (int i=0; i<n; i++)
        {
            if ((dir[i] == 'L' && i>0 && a[i] > a[i-1]) ||
                (dir[i] == 'R' && i<n-1 && a[i] > a[i+1]))
            {
                if (a[i] > max)
                {
                    max = a[i];
                    pos = i;
                }
            }
        }

        if (max == -1)
            break;

        if (dir[pos] == 'L')
        {
            int temp = a[pos];
            a[pos] = a[pos-1];
            a[pos-1] = temp;

            char tempdir = dir[pos];
            dir[pos] = dir[pos-1];
            dir[pos-1] = tempdir;
        }
        else
        {
            int temp = a[pos];
            a[pos] = a[pos+1];
            a[pos+1] = temp;

            char tempdir = dir[pos];
            dir[pos] = dir[pos+1];
            dir[pos+1] = tempdir;
        }

        for (int i=0; i<n; i++)
        {
            if (a[i] > max)
            {
                char d = dir[i];
                if (d == 'L')
                    dir[i] = 'R';
                else
                    dir[i] = 'L';
            }
        }

        print();
    }

    return 0;
}
