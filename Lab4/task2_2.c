#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    char int_str[64];
    char double_str[64];

    // Integer number processing
    printf("Enter an integer (for example, -42): ");
    if (fgets(int_str, sizeof(int_str), stdin))
    {
        char *endptr;
        errno = 0;

        long int_val = strtol(int_str, &endptr, 10);

        if (endptr == int_str)
        {
            printf("Error: no digits recognized for integer number.\n");
        }
        else if (errno == ERANGE)
        {
            printf("Error: range overflow occurred (ERANGE).\n");
        }
        else
        {
            if (*endptr != '\0' && *endptr != '\n')
            {
                printf("Warning: extra characters detected after integer number ('%s').\n", endptr);
            }
            printf("Success: integer number %ld recognized\n", int_val);
        }
    }

    // Floating point number processing
    printf("\nEnter a floating point number (for example, 3.14): ");
    if (fgets(double_str, sizeof(double_str), stdin))
    {
        char *endptr;
        errno = 0;

        double double_val = strtod(double_str, &endptr);

        if (endptr == double_str)
        {
            printf("Error: no digits recognized for floating point number.\n");
        }
        else if (errno == ERANGE)
        {
            printf("Error: range overflow occurred (ERANGE).\n");
        }
        else
        {
            if (*endptr != '\0' && *endptr != '\n')
            {
                printf("Warning: extra characters detected after floating point number ('%s').\n", endptr);
            }
            printf("Success: floating point number %.2f recognized\n", double_val);
        }
    }

    return 0;
}