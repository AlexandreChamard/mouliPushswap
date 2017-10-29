/*
** stats.h for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/include
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sun Oct 29 16:23:52 2017 alexandre Chamard-bois
** Last update Sun Oct 29 18:01:24 2017 alexandre Chamard-bois
*/

#ifndef STATS_H_
# define STATS_H_

# include <sys/time.h>

enum error_type {
	NONE = 0,
	SEGFAULT,
	FLOATING,
	TIMEOUT,
	BAD_CMD,
	CMD_EXEC,
};

typedef struct stats_mouli {
	unsigned int	size;
	unsigned int	nb_loop;
	unsigned int	done;
	unsigned int	failed;
	int		error;
	struct timeval	start_time;
	struct timeval	end_time;
	float		total_time;
	int		verbose;
}	stats_t;

/* TIME */
float timedifference_msec(struct timeval *t0, struct timeval *t1);
void print_time(stats_t *stats);

/* ERROR */
void print_error(stats_t *stats);

/* EXEC */
void print_exec(stats_t *stats);

/* PRINT */
void print_result(stats_t *stats);
#endif
