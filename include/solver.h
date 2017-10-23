/*
** solver.h for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/include
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Oct 21 16:17:32 2017 alexandre Chamard-bois
** Last update Mon Oct 23 11:43:57 2017 alexandre Chamard-bois
*/

#ifndef SOLVER_H_
# define SOLVER_H_

# define NB_CMD		11

typedef struct array {
	int 		nb;
	struct array 	*prev;
	struct array 	*next;
}	array_t;

void	swap_array(array_t *array);
void	rotate_array(array_t **array);
void	rev_rotate_array(array_t **array);
void	push_array(array_t **dest, array_t **source);

typedef struct command {
	char	*command;
	int	who;
	void	(*func)(int, array_t *arrays[2]);
}	command_t;

void	command_s(int who, array_t *arrays[2]);
void	command_r(int who, array_t *arrays[2]);
void	command_rr(int who, array_t *arrays[2]);
void	command_p(int who, array_t *arrays[2]);

/* LIST */
void	free_list(array_t *array);
void	print_array(array_t *array);

int 	read_commands(int fd, array_t *arrays[2]);


/*
	sa	swap a & a + 1
	ra	a = a->next
	rra	a = a->prev
	sb	swap b & b + 1
	rb	b = b->next
	rrb	b = b->prev
	sc	swap a & a + 1; swap b & b + 1
	rc	a = a->next; b = b->next
	rrc	a = a->prev; b = b->prev
	pa	put a -> b
	pb	put b -> a
*/
#endif
