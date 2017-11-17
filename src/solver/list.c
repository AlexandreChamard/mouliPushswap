/*
** list.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 22 21:15:54 2017 alexandre Chamard-bois
** Last update Wed Nov 15 19:31:08 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <stdio.h>
#include "solver.h"
#include "stats.h"

void free_list(array_t *array)
{
	array_t *next;

	if (array) {
		array->prev->next = NULL;
		while (array) {
			next = array->next;
			free(array);
			array = next;
		}
	}
}

static array_t *add_to_list(array_t *array, array_t *new_nb)
{
	if (array) {
		new_nb->prev = array->prev;
		new_nb->next = array;
		array->prev->next = new_nb;
		array->prev = new_nb;
		return (array);
	} else {
		new_nb->prev = new_nb;
		new_nb->next = new_nb;
		return (new_nb);
	}
}

array_t *init_arrays(char **tab)
{
	array_t *array = NULL;
	array_t *new_nb;

	for (int i = 1; tab[i]; i++) {
		if (!(new_nb = malloc(sizeof(array_t)))) {
			perror("malloc");
			free_list(array);
			return (NULL);
		}
		new_nb->nb = atoi(tab[i]);
		array = add_to_list(array, new_nb);
	}
	return (array);
}

void print_array(array_t *array)
{
	array_t *ptr = array;
	int i = 0;

	if (!array) {
		printf("NULL !\n");
		return ;
	}
	while (ptr != array || !i) {
		printf("%d ", ptr->nb);
		ptr = ptr->next;
		i++;
	}
	printf("\n");
}

int verif_output(int fd, char **tab, stats_t *stats)
{
	array_t *arrays[2] = {NULL, NULL};
	int ret;

	if (!(arrays[0] = init_arrays(tab))) {
		return (1);
	}
	gettimeofday(&stats->start_time, NULL);
	ret = read_commands(fd, arrays, stats);
	if (!ret) {
		ret = verif_result(stats, arrays);
	}
	gettimeofday(&stats->end_time, NULL);
	free_list(arrays[0]);
	free_list(arrays[1]);
	return (ret);
}
