#include <stdio.h>

int main(void) {

    double x, y;
    printf("Enter x and y: ");
    scanf("%lf %lf", &x, &y);
    double u = (x + y) / 2.0 + x * y;
    printf("%.3lf\n", u);
    return 0;
}