##
## Makefile for mouliPushswap in /home/alexandre/Documents/tek1/mouliPushswap
##
## Made by alexandre Chamard-bois
## Login   <alexandre@epitech.net>
##
## Started on  Wed Oct 18 22:50:38 2017 alexandre Chamard-bois
## Last update Wed Oct 18 22:50:38 2017 alexandre Chamard-bois
##

CC		=	gcc

CFLAGS		=	-W -Wall -Wextra -Werror
CFLAGS		+=	-I./include

SRC		=	src/main.c			\
			src/help.c			\
			src/execBinary.c		\
			src/parsing.c			\
			src/randomGen.c			\
			src/series.c			\
			src/solver/list.c		\
			src/solver/read_commands.c	\
			src/solver/call_commands.c	\
			src/solver/exec_commands.c	\
			src/stats/error.c		\
			src/stats/time.c		\
			src/stats/exec.c		\
			src/stats/print.c		\

OBJ		=	$(SRC:.c=.o)

NAME		=	mouliPushswap

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all
