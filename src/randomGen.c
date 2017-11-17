/*
** randomGen.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 15:09:54 2017 alexandre Chamard-bois
** Last update Sat Nov 11 11:23:53 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mouli.h"

const int S_BIN = 12;
const int S_NB = 7;

void fill_tab(char **tab, infos_t *infos)
{
	strcpy(tab[0], "./push_swap");
	for (unsigned int i = 1; i <= infos->nb_args; i++) {
		sprintf(tab[i], "%d", RAND(infos));
	}
}

/*  initie les ptr de double tableau; ptr est maintenant de la forme:
[PTR.. * NB_PTR, "./push_swap", NB.. * S_NB]
*/
static inline void addressage(char **tab, char *string, int nb_ptr)
{
	tab[0] = string;
	for (int i = 1; i < nb_ptr; i++) {
		tab[i] = string + S_BIN + (i - 1) * S_NB;
	}
}

/* malloc un ptr de la taille de NB_ARGS ptr + S_BIN + NB_ARGS * S_NB */
char **malloc_ptr(infos_t *infos)
{
	const int size_ptr = (infos->nb_args + 2) * sizeof(char*);
	const int size = (S_BIN + infos->nb_args * S_NB) * sizeof(char) + size_ptr;
	void *ptr;

	if (!(ptr = malloc(size))) {
		return (NULL);
	}
	memset(ptr, 0, size);
	addressage((char**)ptr, (char*)(ptr + size_ptr), infos->nb_args + 1);
	return ((char**)ptr);
}
