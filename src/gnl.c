/*
** EPITECH PROJECT, 2021
** Gnl
** File description:
** gnl
*/

#include "../include/ftp.h"

char *my_realloc(char *ptr, size_t size)
{
    char *temp = ptr;
    int i = 0;

    ptr = malloc(size);
    while (temp[i])
    {
        ptr[i] = temp[i];
        i++;
    }
    free(temp);
    return (ptr);
}

char get_char(const int fd)
{
    static char buff[50];
    static char *ptr_buff;
    static int len = 0;
    char c;

    if (len == 0) {
        len = read(fd, buff, 50);
        ptr_buff = (char *)&buff;
        if (len == 0)
            return (0);
    }
    c = *ptr_buff;
    ptr_buff++;
    len--;
    return c;
}

char *get_next_line(const int fd)
{
    char c;
    char *str = malloc(50 + 1);
    int len = 0;

    if (str == NULL)
        return (0);
    c = get_char(fd);
    while (c != '\n' && c != '\0')
    {
        str[len] = c;
        c = get_char(fd);
        len++;
        if (len % (50+1) == 0)
            str = my_realloc(str, len + 50 + 1);
    }
    str[len] = 0;
    if (c == 0 && str[0] == 0)
        return (0);
    return (str);
}
