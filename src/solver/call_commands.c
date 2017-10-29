/*
** call_commands.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 22:39:13 2017 alexandre Chamard-bois
** Last update Sun Oct 29 16:57:57 2017 alexandre Chamard-bois
*/

#include "solver.h"

int command_s(int who, array_t *arrays[2])
{
	int ret = 0;

	if (who & 0b01) {
		ret += swap_array(arrays[0]);
	}
	if (who & 0b10) {
		ret += swap_array(arrays[1]);
	}
	return (ret);
}

int command_r(int who, array_t *arrays[2])
{
	int ret = 0;

	if (who & 0b01) {
		ret += rotate_array(arrays);
	}
	if (who & 0b10) {
		ret += rotate_array(arrays + 1);
	}
	return (ret);
}

int command_rr(int who, array_t *arrays[2])
{
	int ret = 0;

	if (who & 0b01) {
		ret += rev_rotate_array(arrays);
	}
	if (who & 0b10) {
		ret += rev_rotate_array(arrays + 1);
	}
	return (ret);
}

int command_p(int who, array_t *arrays[2])
{
	int ret = 0;

	if (who & 0b01) {
		ret += push_array(arrays, arrays + 1);
	}
	if (who & 0b10) {
		ret += push_array(arrays + 1, arrays);
	}
	return (ret);
}
