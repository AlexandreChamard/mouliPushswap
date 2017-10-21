/*
** main.c for mouliPushswap in /home/alexandre/Documents/tek1/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Wed Oct 18 22:57:25 2017 alexandre Chamard-bois
** Last update Sat Oct 21 10:59:23 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mouli.h"

int	main(int ac, char **av)
{
	int ret;
	list_t	*series;

	if (ac == 1 || !strcmp(av[1], "help")) {
		print_help(ac, av);
		return (0);
	}
	if (!(series = pars_file(av[1]))) {
		return (1);
	}
	srand(series->infos.seed);
	ret = exec_series(series);
	return (ret);
}
