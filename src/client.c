/*
** EPITECH PROJECT, 2021
** Client
** File description:
** client
*/

#include "../include/ftp.h"

t_client *create_new_client(t_server *server, char *ip)
{
    t_client *new = malloc(sizeof(t_client));

    if (new == NULL)
        return NULL;
    new->fd_mod = -1;
    new->fd = server->fd_clt;
    new->quit = false;
    new->username = NULL;
    new->password = NULL;
    new->log = -42;
    return new;
}

void return_client(t_client *client, char *buff)
{
    char **tab = split_wordtab(buff, " \t\n\r");

    if (buff != NULL) {
        if (my_strlen(buff) > 0) {
            if (tab != NULL) {
                    do_client(tab, client);
                    free_tab(tab);
            } else
                dprintf(client->fd, "500 Unknow command.\n");
        }
        free(buff);
    }
}

void init_client(t_server *server, char *ip)
{
    char *buff = NULL;
    t_client *client = create_new_client(server, ip);

    if (!client)
        return;
    dprintf(client->fd, "220 - Welcome\n");
    for (;;) {
        buff = get_next_line(client->fd);
        return_client(client, buff);
        if (client->ret == -1)
            break;
    }
    free_client(client);
}

int handle_client(t_server *server)
{
    struct sockaddr_in client;
    for (;;) {
        server->fd_clt = accept(server->fd_srv, (struct sockaddr *)
                                &client, &server->sock_in_size);
        if (server->fd_clt != -1) {
            if (fork() == 0) {
                init_client(server, inet_ntoa(client.sin_addr));
                close(server->fd_srv);
                exit(0);
            } else
                close(server->fd_clt);
        }
    }
    close(server->fd_srv);
    return (0);
}
