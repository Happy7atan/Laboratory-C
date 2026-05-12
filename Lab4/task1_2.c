#include <stdio.h>
#include <stdlib.h>

void swapPairs(int *arr, size_t size) {
    for (size_t i = 0; i + 1 < size; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void printArray(const int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    size_t n = 12;

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        arr[i] = (int)(i + 1);
    }

    printf("Original array:\n");
    printArray(arr, n);

    swapPairs(arr, n);

    printf("Array after swapping pairs:\n");
    printArray(arr, n);

    free(arr);

    return 0;
}