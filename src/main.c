/*
** main.c for mouliPushswap in /home/alexandre/Documents/tek1/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Wed Oct 18 22:57:25 2017 alexandre Chamard-bois
** Last update Fri Oct 20 16:16:49 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mouli.h"

void print_series(list_t *serie) {
    printf("min: %d\n", serie->infos.min);
    printf("max: %d\n", serie->infos.max);
    printf("calls: %d\n", serie->infos.calls);
    printf("nb_args: %d\n\n", serie->infos.nb_args);
}

list_t *free_serie(list_t *serie)
{
    list_t *next;

    next = serie->next;
    free(serie);
    return (next);
}

int	main(int ac, char **av)
{
    list_t *series;
	// char *avv[] = {"./push_swap", "42", "24", NULL};

	if (ac == 1 || !strcmp(av[1], "help")) {
		print_help(ac, av);
		return (0);
	}
    if (!(series = pars_file(av[1]))) {
        return (1);
    }
    srand(series->infos.seed);
	// exec_binary(avv);
    while (series) {
        char **ptr = malloc_ptr(&series->infos);
        free(ptr);
        print_series(series);
        series = free_serie(series);
    }
	return (0);
}
