#include <stdio.h>

struct Complex {
    double real;
    double imag;
};

struct Complex add(struct Complex a, struct Complex b) {
    struct Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

struct Complex multiply(struct Complex a, struct Complex b) {
    struct Complex res;
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;
    return res;
}

struct Complex divideByScalar(struct Complex a, double scalar) {
    struct Complex res;
    res.real = a.real / scalar;
    res.imag = a.imag / scalar;
    return res;
}

int main(void) {
    struct Complex z = {1.0, 2.0};
    struct Complex exp_z = {1.0, 0.0};
    struct Complex term = {1.0, 0.0};

    int n = 15;

    for (int i = 1; i <= n; i++) {
        term = multiply(term, z);
        term = divideByScalar(term, (double)i);
        exp_z = add(exp_z, term);
    }

    printf("z = %.2f + %.2fi\n", z.real, z.imag);
    printf("exp(z) = %.5f + %.5fi (after %d iterations)\n", exp_z.real, exp_z.imag, n);

    return 0;
}