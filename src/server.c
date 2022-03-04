/*
** EPITECH PROJECT, 2021
** Server
** File description:
** server
*/

#include "../include/ftp.h"

t_server *get_server(t_server *server, char *port, char *path)
{
    server->pr_e = getprotobyname("TCP");
    server->path = path;
    server->port = atoi(port);
    if (server->pr_e == NULL)
        return NULL;
    int base_server = server->pr_e->p_proto;
    server->fd_srv = socket(AF_INET, SOCK_STREAM, base_server);
    if (server->fd_srv == -1)
        return NULL;
    server->sock_in_size = sizeof(server->sock_in);
    server->sock_in.sin_family = AF_INET;
    server->sock_in.sin_port = htons(server->port);
    server->sock_in.sin_addr.s_addr = INADDR_ANY;
    if (server->fd_srv == -1)
        return (NULL);
    else
        return (server);
}

int init_server(char *port, char *path, t_server *server)
{
    server = get_server(server, port, path);
    if (chdir(path) == -1) {
        fprintf(stderr, "Error: Bad path\n");
        return (84);
    }
    if (server == NULL)
        return (84);
    if (bind(server->fd_srv, (const struct sockaddr *)&server->sock_in,
            sizeof(server->sock_in)) == -1) {
        shutdown(server->fd_srv, 2);
        if (close(server->fd_srv) == -1)
            return (84);
        return (84);
    }
    if (listen(server->fd_srv, 42) == -1 && close(server->fd_srv == -1))
        return (84);
    return (0);
}
