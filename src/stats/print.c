/*
** print.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/stats
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 29 17:32:38 2017 alexandre Chamard-bois
** Last update Sat Nov 11 17:25:08 2017 alexandre Chamard-bois
*/

#include "stats.h"
#include "solver.h"
#include "mouli.h"
#include <stdio.h>

void print_result(stats_t *stats)
{
	printf("\n");
	print_time(stats);
	printf("\n");
	print_exec(stats);
	printf("\n");
}

void avancement(stats_t *stats)
{
	static int cursor = 0;
	const char c[] = "|/-\\";

	cursor = (cursor + 1) % 4;
	printf("\r%c avancement: [", c[cursor]);
	for (unsigned int i = 0; i < 20; i++) {
		if (stats->done + stats->failed >= i * 5 * stats->nb_loop / 100) {
			printf("\e[107m \e[49m");
		} else {
			printf("-");
		}
	}
	printf("]");
	fflush(stdout);
}

void print_info_serie(list_t *serie)
{
	printf("\nmin: %d   max: %d\n", serie->infos.min, serie->infos.max);
	printf("nb series: %d\nsize: %d\n", serie->infos.calls, serie->infos.nb_args);
}

void verbose(const char *str, array_t *arrays[2])
{
	printf("\n%s:\n", str);
	printf("tab1:\n");
	print_array(arrays[0]);
	printf("tab2:\n");
	print_array(arrays[1]);
}
