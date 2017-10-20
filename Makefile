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

CFLAGS		=	-W -Wall -Wextra -Werror -g
CFLAGS		+=	-I./include

SRC		=	src/randomGen.c		\
			src/help.c  		\
			src/execBinary.c  	\

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

test    :   $(NAME)
			cp $(NAME) Pushswap/$(NAME)
