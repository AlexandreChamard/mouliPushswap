/*
** read_commands.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 16:39:57 2017 alexandre Chamard-bois
** Last update Sun Oct 29 17:52:31 2017 alexandre Chamard-bois
*/

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "solver.h"
#include "mouli.h"

static const command_t g_commands[NB_CMD] = {
	{"sa", 0b01, command_s},
	{"sb", 0b10, command_s},
	{"sc", 0b11, command_s},
	{"ra", 0b01, command_r},
	{"rb", 0b10, command_r},
	{"rc", 0b11, command_r},
	{"rra", 0b01, command_rr},
	{"rrb", 0b10, command_rr},
	{"rrc", 0b11, command_rr},
	{"pa", 0b01, command_p},
	{"pb", 0b10, command_p}
};

static int cmp_command(char const *s1, char const *s2)
{
	while (*s1 && !isblank(*s1) && *s1 == *s2) {
		s1++;
		s2++;
	}
	if (isblank(*s1) || *s1 == '\n') {
		return (0);
	}
	return (*s2 - *s1);
}

static int find_cmd(char const *cmd, array_t *arrays[2], stats_t *stats)
{
	for (int i = 0; i < NB_CMD; i++) {
		if (!cmp_command(cmd, g_commands[i].command)) {
			if (g_commands[i].func(g_commands[i].who, arrays)) {
				stats->error = CMD_EXEC;
			}
			return (strlen(g_commands[i].command));
		}
	}
	printf("[%s]\n", cmd);
	stats->error = BAD_CMD;
	return (-1);
}

static void fill_save(char *buff, char *save, char *concat_buff)
{
	char	new_save[5] = "";
	int 	i;

	if (!isblank(buff[BUFF_SIZE]) && buff[BUFF_SIZE] != '\n') {
		for (i = BUFF_SIZE; i >= 0 && !isblank(buff[i]); i--);
		if (i >= 0) {
			buff[i] = 0;
			strncpy(new_save, buff + i + 1, 4);
		}
	}
	strcpy(concat_buff, save);
	strcpy(concat_buff + strlen(save), buff);
	memcpy(save, new_save, 4);
}

/* buff[BUFF_SIZE + 1] */
static int exec_buff(char *buff, char *save_buff, array_t *arrays[2], stats_t *stats)
{
	char		concat_buff[BUFF_SIZE + 5] = "";
	size_t		i = 0;
	int		ret;

	fill_save(buff, save_buff, concat_buff);
	while (concat_buff[i]) {
		ret = find_cmd(concat_buff + i, arrays, stats);
		if (ret == -1) {
			return (1);
		}
		if (concat_buff[i + ret] == '\n') {
			return (0);
		}
		i += ret + 1;
	}
	return (0);
}

int read_commands(int fd, array_t *arrays[2], stats_t *stats)
{
	char save_buff[5] = "";
	char buff[BUFF_SIZE + 1] = "";

	while (read(fd, buff, BUFF_SIZE) > 0) {
		if (exec_buff(buff, save_buff, arrays, stats)) {
			return (1);
		}
		memset(buff, 0, BUFF_SIZE);
	}
	if (exec_buff(buff, save_buff, arrays, stats)) {
		return (1);
	}
	return (0);
}
