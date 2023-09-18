#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void egcd(int x, int y)
{
    // d = gcd(x,y) = ux + vy

    int a1, a2, u1, u2;
    a1 = x, a2 = y, u1 = 1, u2 = 0;
    while (a1 != a2)
    {
        if (a1 > a2)
        {
            a1 -= a2;
            u1 -= u2;
        }
        else
        {
            a2 -= a1;
            u2 -= u1;
        }
    }

    printf("%d, %d, %d\n", a1, u1, (a1 - u1 * x) / y); // prints d,u,v
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}