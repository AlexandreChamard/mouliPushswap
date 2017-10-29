/*
** command.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 16:26:45 2017 alexandre Chamard-bois
** Last update Sun Oct 29 16:54:48 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <stdio.h>
#include "solver.h"

int swap_array(array_t *array)
{
	int tmp;

	if (!array) {
		return (1);
	}
	tmp = array->nb;
	array->nb = array->next->nb;
	array->next->nb = tmp;
	return (0);
}

int rotate_array(array_t **array)
{
	if (!array) {
		return (1);
	}
	(*array) = (*array)->next;
	return (0);
}

int rev_rotate_array(array_t **array)
{
	if (!array) {
		return (1);
	}
	(*array) = (*array)->prev;
	return (0);
}

int push_array(array_t **dest, array_t **source)
{
	array_t *new_source;

	if (!*source) {
		return (1);
	}
	if ((*source)->next != *source) {
		new_source = (*source)->next;
	} else {
		new_source = NULL;
	}
	(*source)->prev->next = (*source)->next;
	(*source)->next->prev = (*source)->prev;
	if (*dest) {
		(*source)->next = *dest;
		(*source)->prev = (*dest)->prev;
		(*dest)->prev->next = *source;
		(*dest)->prev = *source;
	} else {
		(*source)->prev = *source;
		(*source)->next = *source;
	}
	*dest = *source;
	(*source) = new_source;
	return (0);
}
