#include <stdio.h>

int main(void) {
    int a, b;
    int *pa = &a;
    int *pb = &b;

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    printf("%d %d\n", *pa, *pb);
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("%d %d\n", *pa, *pb);
    

    return 0;
}