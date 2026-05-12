#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MY_SIZE 32

int main(void)
{
    char my_string[MY_SIZE];

    printf("Enter a string (For example: abc12): ");
    if (fgets(my_string, sizeof(my_string), stdin))
    {

        size_t len = strlen(my_string);
        if (len > 0 && my_string[len - 1] == '\n')
        {
            my_string[len - 1] = '\0';
        }

        printf("\n--- Step 1. Manual length count by index ---\n");
        size_t len1 = 0;
        for (size_t i = 0; my_string[i] != '\0'; i++)
        {
            len1++;
        }
        printf("String length (by index): %zu\n", len1);

        printf("\n--- Step 2. Manual length count by pointer ---\n");
        size_t len2 = 0;
        char *p = my_string;
        while (*p != '\0')
        {
            len2++;
            p++;
        }
        printf("String length (by pointer): %zu\n", len2);

        printf("\n--- Step 3. Length using strlen ---\n");
        size_t len3 = strlen(my_string);
        printf("String length (strlen): %zu\n", len3);

        printf("\n--- Step 4. String copying ---\n");
        char copy[MY_SIZE];
        strcpy(copy, my_string);
        printf("Original string: %s\n", my_string);
        printf("Copied string: %s\n", copy);

        printf("\n--- Step 5. String concatenation ---\n");
        char concat_buf[MY_SIZE * 2] = "Hello";
        strcat(concat_buf, "World");
        printf("Concatenation result: %s\n", concat_buf);

        printf("\n--- Step 6. String comparison ---\n");
        int cmp_res = strcmp("Hello", "World");
        printf("strcmp(\"Hello\", \"World\") result: %d\n", cmp_res);
        if (cmp_res < 0)
        {
            printf("First string is lexicographically less\n");
        }
        else if (cmp_res == 0)
        {
            printf("Strings are equal\n");
        }
        else
        {
            printf("First string is greater\n");
        }

        printf("\n--- Step 7. Case conversion ---\n");
        char lower_str[MY_SIZE];
        char upper_str[MY_SIZE];

        for (size_t i = 0; my_string[i] != '\0'; i++)
        {
            unsigned char c = (unsigned char)my_string[i];
            lower_str[i] = (char)tolower(c);
            upper_str[i] = (char)toupper(c);
        }

        lower_str[len3] = '\0';
        upper_str[len3] = '\0';

        printf("Original: %s\n", my_string);
        printf("Lowercase: %s\n", lower_str);
        printf("Uppercase: %s\n", upper_str);
    }

    return 0;
}