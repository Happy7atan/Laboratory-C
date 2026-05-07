#include <stdio.h>

struct Date {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 12;
};

int main(void) {
    struct Date myDate;
    myDate.day = 15;
    myDate.month = 4;
    myDate.year = 1707;
    printf("Date: %02u.%02u.%u\n", myDate.day, myDate.month, myDate.year);
    printf("Size of Date struct in memory: %lu bytes\n", sizeof(struct Date));
    return 0;
}