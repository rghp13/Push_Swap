/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:35:57 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/09 14:50:02 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int	*stack;
	int	top;
}				t_stack;
typedef struct s_cont
{
	t_stack	*A;
	t_stack	*B;
	int		stack_max;
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
int				ft_pick_sort(t_cont *cont);
int				ft_swap(t_stack *stck);
int				ft_sa(t_cont *cont);
int				ft_sb(t_cont *cont);
int				ft_ss(t_cont *cont);
int				ft_rotate(t_stack *stck);
int				ft_ra(t_cont *cont);
int				ft_rb(t_cont *cont);
int				ft_rr(t_cont *cont);
int				ft_rrotate(t_stack *stck);
int				ft_rra(t_cont *cont);
int				ft_rrb(t_cont *cont);
int				ft_rrr(t_cont *cont);
int				ft_push(t_stack *from, t_stack *to);
int				ft_pa(t_cont *cont);
int				ft_pb(t_cont *cont);
int				ft_three_size(t_stack *cont, t_cont *container);
int				ft_five_size(t_cont *cont);
int				ft_one_hun_size(t_cont *cont);
int				ft_five_hun_size(t_cont *cont);
int				ft_find_biggest(t_stack *stack);

#endif