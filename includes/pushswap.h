/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:35:57 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/22 17:08:48 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define MALLOC = NULL

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
	t_stack	*a;
	t_stack	*b;
	int		stack_max;
	char	**separated;
}				t_cont;

int				main(int argc, char **argv);
t_cont			*ft_init(int argc, char **separated);
int				ft_free_exit(t_cont *cont);
void			ft_exit(void);
void			ft_free(t_cont *cont);
int				ft_parse(t_cont *cont, char **argv);
int				ft_sep_parse(t_cont *cont, char **separated);
int				ft_check_forbidden(t_cont *cont, char **argv);
int				ft_sep_check_forbidden(t_cont *cont, char **argv);
int				ft_check_string(char *str);
int				ft_check_duplicate(t_cont *cont);
t_cont			*ft_init_cont(char **separated);
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
int				ft_find_small(t_stack *stack);
int				ft_check_sorted(t_cont *cont);
int				ft_make_relative(t_stack *a, int max);
int				ft_find_smallest(t_stack *a, int max);
int				ft_set_duplicate(int *duplicate, int max);
int				ft_find_missing(int *duplicate, int max);
int				ft_array_swap(t_stack *a, int *duplicate);
int				ft_check_bit(t_stack *a, unsigned int mask);
int				ft_check_zero_bit(t_stack *a, unsigned int mask);
int				ft_save_plus_rotate(t_cont *cont, int *pos);
int				ft_calc_rr_dir(t_cont *cont, int pos);
t_cont			*ft_sep_handler(char **separated_input, char **argv);
int				ft_push_three(t_cont *cont);

#endif