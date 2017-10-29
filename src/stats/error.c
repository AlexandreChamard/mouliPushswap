/*
** error.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/stats
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 29 17:18:16 2017 alexandre Chamard-bois
** Last update Sun Oct 29 17:33:25 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include "stats.h"

char *g_error[] = {
	"Segfault",
	"Floating exeption",
	"Timeout",
	"Bad CMD",
	"Error exec cmd",
	NULL
};

void print_error(stats_t *stats)
{
	if (stats->error) {
		printf("%s", g_error[stats->error] - 1);
	}
}
