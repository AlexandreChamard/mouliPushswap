/*
** series.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 10:59:07 2017 alexandre Chamard-bois
** Last update Sat Oct 21 10:59:40 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <stdlib.h>
#include "mouli.h"

void print_series(list_t *serie) {
	printf("min: %d\n", serie->infos.min);
	printf("max: %d\n", serie->infos.max);
	printf("calls: %d\n", serie->infos.calls);
	printf("nb_args: %d\n\n", serie->infos.nb_args);
}

list_t *free_serie(list_t *serie)
{
	list_t	*next;

	next = serie->next;
	free(serie);
	return (next);
}
