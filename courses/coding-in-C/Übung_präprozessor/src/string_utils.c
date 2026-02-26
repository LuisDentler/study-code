#include "../include/string_utils.h"
#include <stdio.h>
#include <stdlib.h>

size_t custom_len(const char *str)
{
    size_t len = 0;

    if (str == NULL)
        return 0;

    while (str[len] != '\0')
        len++;

    return len;
}

char *read_line_dynamic(void)
{
    char buf[1024];
    char *result;
    size_t len;
    size_t i;

    if (fgets(buf, sizeof(buf), stdin) == NULL)
        return NULL;

    /* Zeilenumbruch entfernen, falls vorhanden */
    for (i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] == '\n')
        {
            buf[i] = '\0';
            break;
        }
    }
    len = custom_len(buf);

    result = (char *)malloc(len + 1);
    if (result == NULL)
        return NULL;

    for (i = 0; i <= len; i++)
        result[i] = buf[i];

    return result;
}