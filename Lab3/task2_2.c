#include <stdio.h>

union BytePrinter {
    unsigned long value;
    unsigned char bytes[sizeof(unsigned long)];
};

int main(void) {
    union BytePrinter printer;

    printer.value = 123456789876543210UL;

    printf("Value: %lu\n", printer.value);
    printf("Byte output: ");

    for (int i = 0; i < sizeof(unsigned long); i++) {
        printf("%u ", printer.bytes[i]);
    }
    printf("\n");

    return 0;
}