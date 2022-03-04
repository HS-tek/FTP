/*
** EPITECH PROJECT, 2021
** Main
** File description:
** main
*/

#include "../include/ftp.h"

void display_help(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\t port is the port number on which the server socket listens\n");
    printf
        ("\t path is the path to the home directory for the Anonymous user\n");
}

int main(int ac, char **av)
{
    t_server *server = malloc(sizeof(t_server));

    if (server == NULL)
        return (84);
    if (ac != 3) {
        display_help();
        return (84);
    }
    else {
        if (init_server(av[1], av[2], server) == 84)
            return (84);
        handle_client(server);
        free(server);
    }
    return (0);
}
