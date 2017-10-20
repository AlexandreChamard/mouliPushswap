/*
** randomGen.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 15:09:54 2017 alexandre Chamard-bois
** Last update Fri Oct 20 11:30:12 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "mouli.h"

int create_tab(int size)
{
    char buffer_nb[11];
    char *tab[size + 2];

    tab[0] = strdup("./push_swap");
    for (int i = 1; i <= size; i++) {
        if (!(tab[i] = malloc(sizeof(char) * 11))) {
            return (1);
        }
        memset(tab[i], 0, 11);
        memset(buffer_nb, 0, 11);
        sprintf(buffer_nb, "%d", rand() - (RAND_MAX / 2));
        printf("%s\n", buffer_nb);
        strcpy(tab[i], buffer_nb);
    }
    tab[size + 1] = NULL;
    exec_binary(tab);
    return (0);
}

int main(int ac, char **av)
{
    int min;
    int max;

    if (ac == 1) {
        return (1);
    }
    min = ac > 1 ? atoi(av[1]) : -50000;
    max = ac > 2 ? atoi(av[1]) : -50000;
    srand(ac == 3 ? atoi(av[2]) : time(NULL));
    create_tab(atoi(av[1]));
    return (0);
}
