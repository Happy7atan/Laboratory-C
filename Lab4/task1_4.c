#include <stdio.h>

void cross3(const double a[3], const double b[3], double out[3]) {
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
}

double dot3(const double a[3], const double b[3]) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

double triple3(const double a[3], const double b[3], const double c[3]) {
    double tmp[3];
    cross3(b, c, tmp);
    return dot3(a, tmp);
}

int main(void) {
    double a[3] = {1.0, 0.0, 0.0};
    double b[3] = {0.0, 1.0, 0.0};
    double c[3] = {0.0, 0.0, 1.0};

    double result = triple3(a, b, c);

    printf("mixed multiplication [a, b, c] = %.1lf\n", result);

    return 0;
}