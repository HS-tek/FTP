/*
** EPITECH PROJECT, 2021
** Utils
** File description:
** Utils
*/

#include "../include/ftp.h"

int my_strlen(char const *str)
{
    int n = 0;
    for (;str[n] != '\0'; n++);
    return (n);
}

char *refstr(char const *str)
{
    int i = 0;
    int b = my_strlen(str);
    int c = 0;
    char *refstr = malloc(my_strlen(str));

    for (i ; i != b ; i++) {
        if (str[i] == '-' && (str[i + 1] > 47 && str[i] < 58)) {
            refstr[c] = str[i];
            c++;
        }
        if (str[i] > 47 && str[i] < 58) {
            refstr[c] = str[i];
            c++;
        }
        else if ((str[i] > 58 || str[i] < 48) &&
            (my_strlen(refstr) >= 1 && refstr[0] != '-'))
            return (refstr);
    }
    return (refstr);
}

int my_getnbr(char *str)
{
    int i = 0;
    int res = 1;
    int res1 = 0;
    char *string = malloc(my_strlen(str));

    string = refstr(str);
    if (string[0] == '-') {
        res = -1;
        i++;
    }
    for (i = i ; string[i] != '\0' ; i++) {
        res1 = res1 * 10;
        res1 = res1 + string[i] - '0';
    }
    return (res * res1);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int res = 0;

    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] != s2[j]) {
            res = (s1[i] - s2[j]);
            return (res);
        }
        i++;
        j++;
    }
}
