#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char str[64];

    printf("Enter a string (10-20 characters: letters, digits, punctuation): ");
    if (fgets(str, sizeof(str), stdin))
    {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }

        printf("\nClassification result:\n");
        for (size_t i = 0; str[i] != '\0'; i++)
        {
            unsigned char c = (unsigned char)str[i];

            printf("Character '%c' - ", c);

            if (isalpha(c))
            {
                printf("letter\n");
            }
            else if (isdigit(c))
            {
                printf("digit\n");
            }
            else if (isspace(c))
            {
                printf("space\n");
            }
            else if (ispunct(c))
            {
                printf("punctuation\n");
            }
            else
            {
                printf("other character\n");
            }
        }
    }

    return 0;
}