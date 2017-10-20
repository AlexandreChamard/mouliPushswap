/*
** execBinary.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 00:01:38 2017 alexandre Chamard-bois
** Last update Fri Oct 20 11:29:45 2017 alexandre Chamard-bois
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

void 	read_fd(int fd)
{
	char buffer[100 + 1] = "";
    char *ptr;
    char *token;

	while (read(fd, buffer, 100) > 0) {
        for (ptr = buffer; ; ptr = NULL) {
            token = strtok(ptr, " ");
            if (!token) {
                break;
            }
            printf("%s\n", token);
        }
        memset(buffer, 0, 100);
    }
}

int 		exec_binary(char **av)
{
    int     fds[2];
	int	status = 0;
	pid_t 	pid;

    if (pipe(fds) == -1) {
        return (1);
    }
	if ((pid = fork()) < 0) {
		perror("fork");
		return (1);
	}
	if (!pid) {
        close(fds[0]);
        dup2(fds[1], STDOUT_FILENO);
		execve(av[0], av, NULL);
		perror("exec");
		exit(1);
	} else {
        close(fds[1]);
        dup2(fds[0], STDIN_FILENO);
        read_fd(fds[0]);
		waitpid(pid, &status, 0);
		printf("ended with status: %d\n", status);
		close(fds[0]);
	}
	return (status);
}
