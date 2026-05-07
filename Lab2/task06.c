#include <stdio.h>

int main(void) {
    int a = 1234567890;
    unsigned char *p = (unsigned char *)&a;

    for (int i = 0; i < (int)sizeof(int); i++)
    {
        printf("%u ", *(p + i));
    }
    printf("\n");

    return 0;
}