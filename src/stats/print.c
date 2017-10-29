/*
** print.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/stats
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 29 17:32:38 2017 alexandre Chamard-bois
** Last update Sun Oct 29 17:38:30 2017 alexandre Chamard-bois
*/

#include "stats.h"
#include <stdio.h>

void print_result(stats_t *stats)
{
	print_time(stats);
	printf("\n");
	print_exec(stats);
	printf("\n");
	print_error(stats);
	if (stats->error) {
		printf("\n");
	}
}
