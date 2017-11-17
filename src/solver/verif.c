/*
** verif.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Wed Nov 15 19:15:57 2017 alexandre Chamard-bois
** Last update Wed Nov 15 19:47:28 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include "solver.h"
#include "stats.h"

int verif_result(stats_t *stats, array_t *arrays[2])
{
	array_t *array = arrays[0];

	if (!arrays[0] || arrays[1]) {
		stats->error = BAD_RES;
		return (1);
	}
	array->prev->next = NULL;
	if (!array->next) {
		return (0);
	}
	while (array->next) {
		if (array->nb > array->next->nb) {
			stats->error = BAD_RES;
			return (1);
		}
		array = array->next;
	}
	return (0);
}
