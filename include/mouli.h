/*
** mouli.h for mouliPushswap in /home/alexandre/Documents/tek1/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Wed Oct 18 22:57:25 2017 alexandre Chamard-bois
** Last update Fri Oct 20 16:12:19 2017 alexandre Chamard-bois
*/

#ifndef MOULI_H_
# define MOULI_H_

# define MIN(x, y) ((x) < (y) ? (x) : (y))
# define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct infos {
    int min; // -50.000
    int max; // 49.999
    unsigned int nb_args; // 0
    unsigned int calls; // 10
    unsigned int seed; // TIME
}   infos_t;

typedef struct list {
    infos_t     infos;
    struct list *next;
}   list_t;

/* HELP */
void 	print_help(int ac, char **av);

/*  EXEC_BINARY*/
int 	exec_binary(char **av);

/* ARG */
list_t *pars_file(char const *file);

/* GENERATION */
char **malloc_ptr(infos_t *infos);

#endif
