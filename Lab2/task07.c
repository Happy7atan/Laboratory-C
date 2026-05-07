#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows = 2;
    int cols = 3;
    int i, j;

    int **m = (int **)malloc((size_t)rows * sizeof(int *));
    if (m == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < rows; i++) {
        m[i] = (int *)malloc((size_t)cols * sizeof(int));
        if (m[i] == NULL) {
            printf("Memory allocation failed\n");
            for (j = 0; j < i; j++) {
                free(m[j]);
            }
            free(m);
            return 1;
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}