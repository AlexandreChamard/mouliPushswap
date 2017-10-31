/*
** mouli.h for mouliPushswap in /home/alexandre/Documents/tek1/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Wed Oct 18 22:57:25 2017 alexandre Chamard-bois
** Last update Tue Oct 31 21:49:43 2017 alexandre Chamard-bois
*/

#ifndef MOULI_H_
# define MOULI_H_

# include "stats.h"

# define BUFF_SIZE	1024

# define RAND(infos)	(rand() % (infos->max - infos->min + 1) + infos->min)
# define MIN(x, y)	((x) < (y) ? (x) : (y))
# define MAX(x, y)	((x) > (y) ? (x) : (y))

typedef struct infos {
	int		min; // -50.000
	int		max; // 50.000
	unsigned int	nb_args; // 0
	unsigned int	calls; // 10
	unsigned int	seed; // TIME
}	infos_t;

typedef struct list {
	infos_t     infos;
	struct list *next;
}	list_t;

/* HELP */
void	print_help(int ac, char **av);

/*  EXEC_BINARY*/
int	exec_series(list_t *series);
int	verif_output(int fd, char **tab, stats_t *stats);

/* ARG */
list_t	*pars_file(char const *file);

/* GENERATION */
char	**malloc_ptr(infos_t *infos);
void	fill_tab(char **tab, infos_t *infos);

/* SERIES */
void	print_serie(list_t *serie);
list_t	*free_serie(list_t *serie);

#endif
