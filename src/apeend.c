#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void apend(char **str, unsigned char ch)
{
    char *temp;
    unsigned int size;
    size_t i;

    if (!str || !*str)
    {
        size = 0;
    }
    else
    {
        size = strlen(*str);
    }

    temp = malloc(size + 2);
    if (!temp)
    {
        // Handle memory allocation failure
        return;
    }

    for (i = 0; i < size; i++)
    {
        temp[i] = (*str)[i];
    }

    temp[size] = ch;
    temp[size + 1] = '\0';
    free(*str);
    *str = temp;
}

int main()
{
    char* str = malloc(2);
    if (!str)
    {
        // Handle memory allocation failure
        return 1;
    }

    str[0] = 'h';
    str[1] = '\0';
    apend(&str, 'a');
    apend(&str, 'm');

    printf("%s\n", str);
    free(str);

    return 0;
}