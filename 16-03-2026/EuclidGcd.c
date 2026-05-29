#include <stdio.h>

int q, a, b, r;

int gcd()
{
    while (b != 0)
    {
        r = a%b;
        q = a;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    q = 0;
    printf("Enter first no: ");
    scanf("%d", &a);

    printf("Enter second no: ");
    scanf("%d", &b);
    printf("GCD is %d\n", gcd());
}
