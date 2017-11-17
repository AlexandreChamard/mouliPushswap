/*
** call_commands.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src/solver
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 22:39:13 2017 alexandre Chamard-bois
** Last update Sat Nov 11 16:33:30 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include "solver.h"

static void print_arrays(array_t *arrays[2])
{
	puts("array1:");
	print_array(arrays[0]);
	puts("array2:");
	print_array(arrays[1]);
	putchar('\n');
}

int command_s(int who, array_t *arrays[2], int verbose)
{
	int ret = 0;

	if (who & 0b01) {
		ret += swap_array(arrays[0]);
		if (verbose) {
			puts("sa");
			print_arrays(arrays);
		}
	}
	if (who & 0b10) {
		ret += swap_array(arrays[1]);
		if (verbose) {
			puts("sb");
			print_arrays(arrays);
		}
	}
	return (ret);
}

int command_r(int who, array_t *arrays[2], int verbose)
{
	int ret = 0;

	if (who & 0b01) {
		ret += rotate_array(arrays);
		if (verbose) {
			puts("ra");
			print_arrays(arrays);
		}
	}
	if (who & 0b10) {
		ret += rotate_array(arrays + 1);
		if (verbose) {
			puts("rb");
			print_arrays(arrays);
		}
	}
	return (ret);
}

int command_rr(int who, array_t *arrays[2], int verbose)
{
	int ret = 0;

	if (who & 0b01) {
		ret += rev_rotate_array(arrays);
		if (verbose) {
			puts("rra");
			print_arrays(arrays);
		}
	}
	if (who & 0b10) {
		ret += rev_rotate_array(arrays + 1);
		if (verbose) {
			puts("rrb");
			print_arrays(arrays);
		}
	}
	return (ret);
}

int command_p(int who, array_t *arrays[2], int verbose)
{
	int ret = 0;

	if (who & 0b01) {
		ret += push_array(arrays, arrays + 1);
		if (verbose) {
			puts("pa");
			print_arrays(arrays);
		}
	}
	if (who & 0b10) {
		ret += push_array(arrays + 1, arrays);
		if (verbose) {
			puts("pb");
			print_arrays(arrays);
		}
	}
	return (ret);
}
