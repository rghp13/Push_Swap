#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

typedef struct	s_stack
{
	int	*stack;
	int	top;//top of stack is empty spot after latest input, if == to max then stop
}				t_stack;
typedef struct	s_cont
{
	t_stack *A;
	t_stack *B;
	int stack_max;
}				t_cont;

int				ft_pushswap(int argc, char **argv);
t_cont			*ft_init(int argc, char **argv);
int				ft_free_exit(t_cont *cont);

#endif