/*
** randomGen.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 15:09:54 2017 alexandre Chamard-bois
** Last update Fri Oct 20 16:18:14 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "mouli.h"

const int S_BINARY = 12;
const int S_NB = 7;

/*  initie les ptr de double tableau; ptr est maintenant de la forme:
    [PTR.. * NB_PTR, "./push_swap", NB.. * S_NB]
*/
static inline void addressage(char **tab, char *string, int nb_ptr)
{
    tab[0] = string;
    for (int i = 1; i < nb_ptr; i++) {
        tab[i] = string + S_BINARY + (i - 1) * S_NB;
    }
}

/* malloc un ptr de la taille de NB_ARGS ptr + S_BINARY + NB_ARGS * S_NB */
char **malloc_ptr(infos_t *infos)
{
    int size_ptr = (infos->nb_args + 2) * sizeof(char*);
    int size =  (S_BINARY + infos->nb_args * S_NB) * sizeof(char) + size_ptr;
    void *ptr;

    if (!(ptr = malloc(size))) {
        return (NULL);
    }
    memset(ptr, 0, size);
    strcpy(ptr + size_ptr, "./push_swap");
    addressage((char**)ptr, (char*)(ptr + size_ptr), infos->nb_args + 1);
    return ((char**)ptr);
}

int create_tab(infos_t *infos)
{
    char buffer_nb[11];
    char *tab[infos->nb_args + 2];

    tab[0] = strdup("./push_swap");
    for (unsigned int i = 1; i <= infos->nb_args; i++) {
        if (!(tab[i] = malloc(sizeof(char) * 11))) {
            return (1);
        }
        memset(tab[i], 0, 11);
        memset(buffer_nb, 0, 11);
        sprintf(buffer_nb, "%d", rand() - (RAND_MAX / 2));
        printf("%s\n", buffer_nb);
        strcpy(tab[i], buffer_nb);
    }
    tab[infos->nb_args + 1] = NULL;
    exec_binary(tab);
    return (0);
}
