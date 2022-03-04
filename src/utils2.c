/*
** EPITECH PROJECT, 2021
** Utils2
** File description:
** utils2
*/

#include "../include/ftp.h"

char **split_wordtab(char *str, char *str2)
{
    int i = 0;
    char **tab = malloc(sizeof(char *));
    char *token = strtok(str, str2);

    if (!str || !tab || !token)
        return (NULL);
    for (;;) {
        tab[i] = strdup(token);
        i++;
        tab = realloc(tab, (sizeof(char *) * (i + 1)));
        token = strtok(NULL, str2);
        if (token == NULL){
            tab[i] = token;
            break;
        }
    }
    free(token);
    return (tab);
}

void free_tab(char **tab)
{
    int i = 0;
    for (i ; tab[i] ; i++)
        free(tab[i]);
    free(tab[i]);
}

void free_client(t_client *client)
{
    if (close(client->fd) == -1 || close(client->fd_mod == -1))
        exit(84);
    free(client->username);
    free(client->password);
    free(client);
}
