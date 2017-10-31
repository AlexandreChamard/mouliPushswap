/*
** execBinary.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 00:01:38 2017 alexandre Chamard-bois
** Last update Tue Oct 31 21:38:56 2017 alexandre Chamard-bois
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "mouli.h"
#include "stats.h"

static void exec_child(int fds[2], char **tab)
{
	close(fds[0]);
	dup2(fds[1], STDOUT_FILENO);
	execve(tab[0], tab, NULL);
	perror("exec");
	exit(1);
}

static int exec_father(int fds[2], int pid, char **tab, stats_t *stats)
{
	int status = 0;

	usleep(stats->size);
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	verif_output(fds[0], tab, stats);
	waitpid(pid, &status, 0);
	close(fds[0]);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGFPE) {
			stats->error = FLOATING;
		} else if (WTERMSIG(status) == SIGSEGV) {
			stats->error = SEGFAULT;
		}
	}
	return (status);
}

int		exec_binary(char **tab, stats_t *stats)
{
	int	status = 0;
	int     fds[2];
	pid_t 	pid;

	if (pipe(fds) == -1) {
		perror("pipe");
		return (1);
	}
	if ((pid = fork()) < 0) {
		perror("fork");
		return (1);
	}
	if (!pid) {
		exec_child(fds, tab);
	} else {
		status = exec_father(fds, pid, tab, stats);
	}
	return (status);
}

int exec_series(list_t *series)
{
	char	**tab;
	stats_t	stats;

	while (series) {
		memset(&stats, 0, sizeof(stats_t));
		if (!(tab = malloc_ptr(&series->infos))) {
			return (1);
		}
		stats.nb_loop = series->infos.calls;
		stats.size = series->infos.nb_args;
		for (unsigned int i = 0; i < stats.nb_loop; i++) {
			stats.error = NONE;
			fill_tab(tab, &series->infos);
			exec_binary(tab, &stats);
			stats.total_time +=
			timedifference_msec(&stats.start_time, &stats.end_time);
			if (stats.error) {
				printf("error: %d\n", stats.error);
				stats.failed++;
			} else {
				stats.done++;
			}
			printf("%d\n", i);
		}
		free(tab);
		print_result(&stats);
		series = free_serie(series);
	}
	return (0);
}
