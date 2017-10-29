/*
** exec.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/stats
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 29 17:26:43 2017 alexandre Chamard-bois
** Last update Sun Oct 29 17:35:50 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include "stats.h"

void print_exec(stats_t *stats)
{
	printf("Nb execution: %d\tNb success: %d\tNb Fail: %d",
	stats->nb_loop, stats->done, stats->failed);
}
