/*
** call_commands.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 22:39:13 2017 alexandre Chamard-bois
** Last update Sat Oct 21 23:12:31 2017 alexandre Chamard-bois
*/

#include "solver.h"

void command_s(int who, array_t *arrays[2])
{
	if (who & 0x1) {
		swap_array(arrays[0]);
	}
	if (who & 0x2) {
		swap_array(arrays[1]);
	}
}

void command_r(int who, array_t *arrays[2])
{
	if (who & 0x1) {
		rotate_array(arrays);
	}
	if (who & 0x2) {
		rotate_array(arrays + 1);
	}
}

void command_rr(int who, array_t *arrays[2])
{
	if (who & 0x1) {
		rev_rotate_array(arrays);
	}
	if (who & 0x2) {
		rev_rotate_array(arrays + 1);
	}
}

void command_p(int who, array_t *arrays[2])
{
	if (who & 0x1) {
		push_array(arrays, arrays + 1);
	}
	if (who & 0x2) {
		push_array(arrays + 1, arrays);
	}
}
