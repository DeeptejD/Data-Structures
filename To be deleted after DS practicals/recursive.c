#include <stdio.h>
#include <stdlib.h>

void base_conv(int num, int base)
{
    int rem = num % base;
    if (num == 0)
        return;
    base_conv(num / base, base);
    if (rem < 10)
        printf("%d", rem);
    else
        printf("%c", (rem - 10) + 'A');
}

void hanoi(int n, char source, char temp, char dest)
{
    if (n == 1)
    {
        printf("Move %d from %c to %c\n", n, source, dest);
        return;
    }
    hanoi(n - 1, source, dest, temp);
    printf("Move %d from %c to %c\n", n, source, dest);
    hanoi(n - 1, temp, source, dest);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    gcd(b, a % b);
}

void rev(char expr[])
{
    if (*expr == '\0')
        return;
    rev(expr + 1);
    putchar(*expr);
}



int main(int argc, char const *argv[])
{
    base_conv(10, 2);
    printf("\n");
    base_conv(10, 8);
    printf("\n");
    base_conv(10, 16);
    hanoi(4, 'A', 'B', 'C');
    printf("\n%d\n", gcd(1238, 45));
    rev("godzilla");
    return 0;
}
