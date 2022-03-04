/*
** EPITECH PROJECT, 2021
** Cmd
** File description:
** Cmd
*/

#include "../include/ftp.h"

void function(char **tab, t_client *clt, int i)
{
    static void (*function[5])(char **tab, t_client *clt) =
        {&user, &pass, &quit, &help, &noop};

    (*function[i])(tab, clt);
}

int do_cmd(char **tab, t_client *clt)
{
    static const char *func[6] = {"USER", "PASS", "QUIT", "HELP",
        "NOOP", NULL};

    for (int i = 0; func[i] != NULL ; i++) {
        if (strcasecmp(tab[0], func[i]) == 0) {
            function(tab, clt, i);
            return (0);
        }
    }
    return (1);
}

void do_client(char **tab, t_client *client)
{
    if (tab == NULL)
        dprintf(client->fd, "500 Unknow command.\n");
    else if (do_cmd(tab, client) == 0)
        return;
    else {
        dprintf(client->fd, "530.\n");
        return;
    }
}
