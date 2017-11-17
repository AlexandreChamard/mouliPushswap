/*
** time.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 29 17:08:46 2017 alexandre Chamard-bois
** Last update Fri Nov 17 12:07:14 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <time.h>
#include "stats.h"

int timeout(time_t start, int time_max)
{
	if (time_max > 0) {
		return (time(NULL) - start >= time_max);
	}
	return (0);
}

float timedifference_msec(struct timeval *t0, struct timeval *t1)
{
	return 	((t1->tv_sec - t0->tv_sec) * 1000.0f +
		(t1->tv_usec - t0->tv_usec) / 1000.0f);
}

void print_time(stats_t *stats)
{
	printf("moyenne temps :\t%.3f s.", stats->total_time / (stats->done +  stats->failed) / 1000);
}
