/*
** read_commands.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 16:39:57 2017 alexandre Chamard-bois
** Last update Sat Oct 21 23:40:42 2017 alexandre Chamard-bois
*/

#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include "solver.h"
#include "mouli.h"

static const command_t g_commands[NB_CMD] = {
	{"sa", 1, command_s},
	{"sb", 2, command_s},
	{"sc", 3, command_s},
	{"ra", 1, command_r},
	{"rb", 2, command_r},
	{"rc", 3, command_r},
	{"rra", 1, command_rr},
	{"rrb", 2, command_rr},
	{"rrc", 3, command_rr},
	{"pa", 1, command_p},
	{"pb", 2, command_p}
};

static int cmp_command(char const *s1, char const *s2)
{
	while (*s1 && !isblank(*s1) && *s1 == *s2) {
		s1++;
		s2++;
	}
	if (isblank(*s1)) {
		return (0);
	}
	return (*s2 - *s1);
}

int find_cmd(char const *cmd, array_t *arrays[2])
{
	for (int i = 0; i < NB_CMD; i++) {
		if (!cmp_command(cmd, g_commands[i].command)) {
			g_commands[i].func(g_commands[i].who, arrays);
			return (strlen(g_commands[i].command));
		}
	}
	return (-1);
}

void fill_save(char *buff, char *save, char *concat_buff)
{
	char	new_save[4] = "";
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
/* ne pas oublier de rappeller la fonction pour flush la dernière save */
int exec_buff(char *buff, array_t *arrays[2])
{
	static char	save_buff[4] = "";
	char		concat_buff[BUFF_SIZE + 5] = "";
	size_t i = 0;
	int ret;

	fill_save(buff, save_buff, concat_buff);
	while (concat_buff[i]) {
		ret = find_cmd(concat_buff + i, arrays);
		if (ret == -1) {
			return (-1);
		}
		if (concat_buff[i + ret] == '\n') {
			return (1);
		}
		i += ret + 1;
	}
	return (0);
}

int read_commands(int fd, char **tab)
{
	char buff[BUFF_SIZE + 1] = "";
	array_t *arrays[2] = {NULL, NULL};

	(void) tab;
	/* initie les arrays */
	while (read(fd, buff, BUFF_SIZE) > 0) {
		exec_buff(buff, arrays);
		memset(buff, 0, BUFF_SIZE);
	}
	memset(buff, 0, BUFF_SIZE);
	exec_buff(buff, arrays);
	return (0);
}
