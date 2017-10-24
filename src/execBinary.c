/*
** execBinary.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 00:01:38 2017 alexandre Chamard-bois
** Last update Tue Oct 24 23:52:16 2017 alexandre Chamard-bois
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>
#include "mouli.h"

static void exec_child(int fds[2], char **tab)
{
	close(fds[0]);
	dup2(fds[1], STDOUT_FILENO);
	execve(tab[0], tab, NULL);
	perror("exec");
	exit(1);
}

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

static int exec_father(int fds[2], int pid, char **tab)
{
	int status = 0;
	struct timeval stop, start;

	gettimeofday(&start, NULL);
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	verif_output(fds[0], tab);
	waitpid(pid, &status, 0);
	gettimeofday(&stop, NULL);

	printf("ended with status: %d in %f ms.\n", status, timedifference_msec(start, stop));
	close(fds[0]);
	return (status);
}

int		exec_binary(char **tab)
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
		status = exec_father(fds, pid, tab);
	}
	return (status);
}

int exec_series(list_t *series)
{
	char **tab;

	while (series) {
		if (!(tab = malloc_ptr(&series->infos))) {
			return (1);
		}
		for (unsigned int i = 0; i < series->infos.calls; i++) {
			fill_tab(tab, &series->infos);
			exec_binary(tab);
		}
		free(tab);
		series = free_serie(series);
	}
	return (0);
}
