/*
** EPITECH PROJECT, 2021
** Ftp
** File description:
** ftp
*/

#ifndef MYFTP_H_
#define MYFTP_H_
#include <stdio.h>
#include <ctype.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#include <stdarg.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <dirent.h>
#include <netdb.h>

typedef struct s_server {
    int fd_srv;
    int fd_clt;
    int port;
    char *path;
    struct protoent *pr_e;
    struct sockaddr_in sock_in;
    socklen_t sock_in_size;
} t_server;

typedef struct s_client {
    int fd;
    char *username;
    char *password;
    int fd_mod;
    int log;
    bool quit;
    int ret;
} t_client;

//_____________________________________________SERVER/CLIENT

int init_server(char *port, char *path, t_server *server);
int handle_client(t_server *server);
void do_client(char **tab, t_client *clientt);

//______________________________________________COMMANDS

void user(char **name, t_client *client);
void pass(char **name, t_client *client);
void help(char **name, t_client *client);
void quit(char **name, t_client *client);
void noop(char **name, t_client *client);

//______________________________________________MAIN

void display_help(void);
int main(int ac, char **av);

//______________________________________________LIB

int my_strlen(char const *str);
char *refstr(char const *str);
int my_getnbr(char *str);
int my_strcmp(char const *s1, char const *s2);
char *get_next_line(const int fd);
char **split_wordtab(char *str, char *str2);
void free_tab(char **tab);
void free_client(t_client *clientt);

#endif /* MYFTP_H_ */
