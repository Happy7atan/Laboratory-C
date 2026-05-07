#include <stdio.h>
#include <stdlib.h>

enum DataType {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR
};

struct TaggedData {
    enum DataType type;
    union {
        int i;
        float f;
        char c;
    } data;
};

int main(void) {
    int n = 3;

    struct TaggedData *arr = (struct TaggedData *)malloc((size_t)n * sizeof(struct TaggedData));
    if (arr == NULL) {
        printf("memory allocation error\n");
        return 1;
    }

    arr[0].type = TYPE_INT;
    arr[0].data.i = 100;

    arr[1].type = TYPE_FLOAT;
    arr[1].data.f = 3.14f;

    arr[2].type = TYPE_CHAR;
    arr[2].data.c = 'Z';

    printf("Data in the array:\n");
    for (int i = 0; i < n; i++) {
        printf("component %d: ", i);

        switch (arr[i].type) {
        case TYPE_INT:
            printf("Type INT, value = %d\n", arr[i].data.i);
            break;
        case TYPE_FLOAT:
            printf("Type FLOAT, value = %.2f\n", arr[i].data.f);
            break;
        case TYPE_CHAR:
            printf("Type CHAR, value = %c\n", arr[i].data.c);
            break;
        }
    }

    free(arr);

    return 0;
}