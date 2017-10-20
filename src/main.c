/*
** main.c for mouliPushswap in /home/alexandre/Documents/tek1/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Wed Oct 18 22:57:25 2017 alexandre Chamard-bois
** Last update Thu Oct 19 00:23:23 2017 alexandre Chamard-bois
*/

#include <string.h>
#include "mouli.h"

int	main(int ac, char **av, char **env)
{
	char *avv[] = {"./push_swap", "42", "24", NULL};

	if (ac == 1 || !strcmp(av[1], "help")) {
		print_help(ac, av);
		return (0);
	}
	exec_binary(avv);
	return (0);
}
