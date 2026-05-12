#include <stdio.h>

int factorial_iter(int n) {
    if (n <= 1)
    {
        return 1;
    }
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int factorial_rec(int n) {
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial_rec(n - 1);
}

int main(void) {
    int n;
    printf("Enter n:");
    if (scanf("%d", &n) == 1 && n >= 0)
    {
        printf("%d\n", factorial_iter(n));
        printf("%d\n", factorial_rec(n));
    }

    return 0;
}