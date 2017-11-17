/*
** main.c for mouliPushswap in /home/alexandre/Documents/tek1/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Wed Oct 18 22:57:25 2017 alexandre Chamard-bois
** Last update Sat Nov 11 17:38:29 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <sys/stat.h>
#include "mouli.h"

int	main(int ac, char **av)
{
	struct stat stats;
    struct termios	term;
    struct termios	save;
    list_t	*series;
	int ret;

	if (stat("push_swap", &stats) == -1) {
		puts("Binary not found.");
		return (1);
	}
	if (ac == 1 || !strcmp(av[1], "help")) {
		print_help(ac, av);
		return (0);
	}
	if (!(series = pars_file(av[1]))) {
		return (1);
	}
    tcgetattr(0, &term);
    save = term;
    term.c_lflag &= ~(ICANON);
    term.c_cc[VMIN] = 0;
    term.c_cc[VTIME] = 10;
    tcsetattr(0, TCSANOW, &term);
	srand(series->infos.seed);
	ret = exec_series(series);
    tcsetattr(0, TCSANOW, &save);
	return (ret);
}
