#include <stdio.h>

int main(void) {

    int a, b;
    int *pa = &a;
    int *pb = &b;
    
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    

        if (*pa > *pb)
        {
            printf("%d\n", *pa);
        }
        else
        {
            printf("%d\n", *pb);
        }


    return 0;
}