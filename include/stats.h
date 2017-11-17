/*
** stats.h for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/include
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 29 16:23:52 2017 alexandre Chamard-bois
** Last update Fri Nov 17 11:47:58 2017 alexandre Chamard-bois
*/

#ifndef STATS_H_
# define STATS_H_

# include <sys/time.h>
#include "solver.h"

enum error_type {
	NONE = 0,
	SEGFAULT,
	FLOATING,
	BAD_RES,
	TIMEOUT,
	BAD_CMD,
	CMD_EXEC,
	BAD_EOL,
};

#ifndef STATS_T
# define STATS_T
typedef struct stats_mouli {
	unsigned int	size;
	unsigned int	nb_loop;
	unsigned int	done;
	unsigned int	failed;
	int		error;
	int		timeout;
	int		time_max;
	struct timeval	start_time;
	struct timeval	end_time;
	float		total_time;
	int		verbose;
	int		debug;
}	stats_t;
#endif

#ifndef ARRAY_T
# define ARRAY_T
typedef struct array {
	int 		nb;
	struct array 	*prev;
	struct array 	*next;
}	array_t;
#endif

/* TIME */
float timedifference_msec(struct timeval *t0, struct timeval *t1);
void print_time(stats_t *stats);
int timeout(time_t start, int time_max);

/* ERROR */
void print_error(stats_t *stats);

/* EXEC */
void print_exec(stats_t *stats);

/* PRINT */
void print_result(stats_t *stats);
void avancement(stats_t *stats);
void verbose(const char *str, array_t *arrays[2]);

#endif
