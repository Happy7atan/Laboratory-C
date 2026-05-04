#include <stdio.h>

int main(void) {
    int n;
    int a[100];

    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        printf("%d ", a[i] * a[i]);
    }
    printf("\n");
    return 0;
}