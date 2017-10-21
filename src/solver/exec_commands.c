/*
** command.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 16:26:45 2017 alexandre Chamard-bois
** Last update Sat Oct 21 22:56:49 2017 alexandre Chamard-bois
*/

#include "solver.h"

void swap_array(array_t *array)
{
	int tmp = array->nb;

	array->nb = array->next->nb;
	array->next->nb = tmp;
}

void rotate_array(array_t **array)
{
	(*array) = (*array)->next;
}

void rev_rotate_array(array_t **array)
{
	(*array) = (*array)->prev;
}

void push_array(array_t **dest, array_t **source)
{
	array_t *new_source;

	if (*source) {
		new_source = (*source)->next;
		(*source)->prev->next = (*source)->next;
		(*source)->next->prev = (*source)->prev;
		if (*dest) {
			(*dest)->prev->next = *source;
			(*dest)->prev = *source;
		}
		*dest = *source;
		(*source) = new_source;
	}
}
