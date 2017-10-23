/*
** list.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 22 21:15:54 2017 alexandre Chamard-bois
** Last update Mon Oct 23 12:12:00 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <stdio.h>
#include "solver.h"

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

int verif_output(int fd, char **tab)
{
	array_t *arrays[2] = {NULL, NULL};
	int ret;

	if (!(arrays[0] = init_arrays(tab))) {
		return (1);
	}
	printf("start:\n");
	print_array(arrays[0]);

	ret = read_commands(fd, arrays);
	printf("error: %d\n", ret);
	printf("array[0]:\n");
	print_array(arrays[0]);
	printf("array[1]:\n");
	print_array(arrays[1]);
	printf("\n");
	return (0);
}
