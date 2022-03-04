/*
** EPITECH PROJECT, 2021
** Command
** File description:
** command
*/

#include "../include/ftp.h"

void help(char **name, t_client *client)
{
    if (client->log <= 0)
        dprintf(client->fd, "530 Login with USER and PASS.\n");
    else {
        dprintf(client->fd, "214-Use the following commands:"   \
                "\n USER PASS HELP NOOP QUIT\n");
        dprintf(client->fd, "214 Help OK.\n");
    }
    (void)name;
}

void user(char **name, t_client *client)
{
    if (name[0] && !name[1] && client->log != 42)
        dprintf(client->fd, "530 Permission denied.\n");
    else {
        free(client->username);
        client->log = 0;
        client->username = strdup(name[1]);
        dprintf(client->fd, "331 Enter the password.\n");
    }
}

void pass(char **name, t_client *client)
{
    if (client->log != -42) {
        if (client->log == 42)
            dprintf(client->fd, "230 Already logged in.\n");
        else if (strcmp(client->username, "Anonymous")) {
            dprintf(client->fd, "530 Login incorrect.\n");
        } else {
            free(client->password);
            dprintf(client->fd, "230 Login successful.\n");
            if (name[1] != NULL)
                client->password = strdup(name[1]);
            client->log = 42;
        }
    }
    else
        dprintf(client->fd, "530 Login with USER first.\n");
}

void quit(char **name, t_client *client)
{
    if (name[0]) {
        dprintf(client->fd, "221 Exit.\n");
        client->ret = -1;
    }
    close(client->fd);
}

void noop(char **name, t_client *client)
{
    (void)name;
    if (client->log <= 0)
        dprintf(client->fd, "530 Login with USER and PASS.\n");
    else
        dprintf(client->fd, "200 NOOP ok.\n");
}
