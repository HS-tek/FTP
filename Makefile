##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME	=	myftp

CC	=	gcc -o

CFLAGS	=	-Wall -Wextra -I./include/

SRC	=	src/main.c		\
		src/server.c		\
		src/utils.c		\
		src/utils2.c		\
		src/client.c		\
		src/gnl.c		\
		src/command.c		\
		src/cmd.c		\

OBJ	=	$(SRC:.c=.o)

all : 		$(NAME)

$(NAME) :	$(OBJ)
		$(CC) $(NAME) $(SRC)
		@printf "[\033[0;32mbuilt\033[0m] %s\n" $(NAME)

clean :
		rm -f $(OBJ)
		@printf "[\033[0;36mdeleted\033[0m] %s\n" $(NAME)

fclean : clean
		rm -f $(NAME)
		@printf "[\033[0;36mdeleted\033[0m] %s\n" $(NAME)

re : fclean all
