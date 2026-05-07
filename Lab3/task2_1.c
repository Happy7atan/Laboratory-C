#include <stdio.h>

union Data {
    int i;
    float f;
};

int main(void) {
    union Data myData;
    union Data *ptr = &myData;

    ptr->i = 42;
    printf("Value of ptr->i : %d\n", ptr->i);
    ptr->f = 3.14f;
    printf("Value of ptr->f : %.2f\n", ptr->f);
    printf("Value of ptr->i after writing to f: %d\n", ptr->i);

    return 0;
}