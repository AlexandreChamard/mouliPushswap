/*
** read_commands.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 16:39:57 2017 alexandre Chamard-bois
** Last update Tue Oct 31 21:54:02 2017 alexandre Chamard-bois
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

static int find_cmd(char const *cmd, array_t *arrays[2], stats_t *stats, int nb_loop)
{
	for (int i = 0; i < NB_CMD; i++) {
		if (!cmp_command(cmd, g_commands[i].command)) {
			if (g_commands[i].func(g_commands[i].who, arrays)) {
				stats->error = CMD_EXEC;
			}
			return (strlen(g_commands[i].command));
		}
	}
	stats->error = BAD_CMD;
	return (-1);
}

static void fill_save(char *buff, char *save, char *concat_buff)
{
	char	new_save[5] = "";
	int	buff_size = strlen(buff) - 1;
	int 	i;

	if (!isblank(buff[buff_size]) && buff[buff_size] != '\n') {
		for (i = buff_size; i >= 0 && !isblank(buff[i]); i--);
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
static int exec_buff(char *buff, char *save_buff, array_t *arrays[2], stats_t *stats, int nb_loop)
{
	char		concat_buff[BUFF_SIZE + 5] = "";
	size_t		i;
	int		ret;

	fill_save(buff, save_buff, concat_buff);
	 i = isblank(*concat_buff);
	while (concat_buff[i]) {
		ret = find_cmd(concat_buff + i, arrays, stats, nb_loop);
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
	int i = 0;
	char buff[BUFF_SIZE + 1] = "";

	while (read(fd, buff, BUFF_SIZE) > 0) {
		if (exec_buff(buff, save_buff, arrays, stats, i)) {
			return (1);
		}
		memset(buff, 0, BUFF_SIZE);
		i++;
	}
	if (exec_buff(buff, save_buff, arrays, stats, i)) {
		return (1);
	}
	return (0);
}
