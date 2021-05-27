#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

typedef struct	s_stack
{
	int	*stack;
	int	top;
}				t_stack;
typedef struct	s_cont
{
	t_stack *A;
	t_stack *B;
	int stack_max;
}				t_cont;

int				ft_pushswap(int argc, char **argv);
t_cont			*ft_init(int argc);
void			ft_free_exit(t_cont *cont);
void			ft_exit(void);
void			ft_free(t_cont *cont);
int				ft_parse(t_cont *cont, char **argv);
int				ft_check_forbidden(t_cont *cont, char **argv);
int				ft_check_string(char *str);
int				ft_check_duplicate(t_cont *cont);
t_cont			*ft_init_cont(void);
int				ft_init_values(int argc, t_cont *cont);


#endif