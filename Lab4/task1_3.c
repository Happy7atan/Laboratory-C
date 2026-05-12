#include <stdio.h>
#include <stdlib.h>

// 1. Функция выделения памяти
double **allocate_matrix(size_t rows, size_t cols) {

    double **matrix = (double **)malloc(rows * sizeof(double *));
    if (matrix == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// 2. Функция освобождения памяти
void free_matrix(double **matrix, size_t rows) {
    if (matrix != NULL) {
        for (size_t i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}

// 3. Функция заполнения матрицы
void fill_matrix(double **matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

// 4. Функция печати матрицы
void print_matrix(double **matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    size_t rows = 2;
    size_t cols = 3;

    double **matrix = allocate_matrix(rows, cols);
    if (matrix == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    fill_matrix(matrix, rows, cols);

    print_matrix(matrix, rows, cols);

    free_matrix(matrix, rows);

    return 0;
}