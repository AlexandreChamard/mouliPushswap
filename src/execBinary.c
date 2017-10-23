/*
** execBinary.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 00:01:38 2017 alexandre Chamard-bois
** Last update Mon Oct 23 11:25:31 2017 alexandre Chamard-bois
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
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

static int exec_father(int fds[2], int pid, char **tab)
{
	int status = 0;

	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	verif_output(fds[0], tab);
	waitpid(pid, &status, 0);
	printf("ended with status: %d\n", status);
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
		fill_tab(tab, &series->infos);
		exec_binary(tab);
		free(tab);
		series = free_serie(series);
	}
	return (0);
}
