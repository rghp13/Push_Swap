/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:20:48 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/22 15:13:22 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**You want the oldest item in the stack to be the smallest
**
** 
*/

int	ft_three_size(t_stack *cont, t_cont *container)
{
	int	max;

	max = cont->top - 1;
	if (cont->stack[max] > cont->stack[max - 1] && cont->stack[max] > \
	cont->stack[max - 2])
	{
		ft_ra(container);
		if (cont->stack[max] > cont->stack[max - 1])
			ft_sa(container);
	}
	else if (cont->stack[max - 1] > cont->stack[max] && cont->stack[max - 1] > \
	cont->stack[max - 2])
	{
		ft_rra(container);
		if (cont->stack[max] > cont->stack[max - 1])
			ft_sa(container);
	}
	else if (cont->stack[max - 2] > cont->stack[max] && cont->stack[max - 2] > \
	cont->stack[max - 1])
	{
		if (cont->stack[max] > cont->stack[max - 1])
			ft_sa(container);
	}
	return (0);
}

int	ft_push_three(t_cont *cont)
{
	int	push;

	while (cont->a->top > 3)
	{
		push = ft_find_small(cont->a);
		while (push < cont->a->top - 1)
		{
			if (push == cont->a->top - 2)
				ft_sa(cont);
			else if (push == 0 || push == 1)
				ft_rra(cont);
			else
				ft_ra(cont);
			push = ft_find_small(cont->a);
		}
		ft_pb(cont);
	}
	return (0);
}

int	ft_one_hun_size(t_cont *cont)
{
	unsigned int	mask;
	int				pos;

	mask = 1;
	while (mask)
	{
		if (ft_check_zero_bit(cont->a, mask))
		{
			mask = mask << 1;
			continue ;
		}
		pos = -1;
		while (cont->a->top > 0 && ft_check_bit(cont->a, mask))
		{
			if ((cont->a->stack[cont->a->top - 1] & mask) == 0)
				ft_pb(cont);
			else
				ft_save_plus_rotate(cont, &pos);
		}
		ft_calc_rr_dir(cont, pos);
		while (cont->b->top > 0)
			ft_pa(cont);
		mask = mask << 1;
	}
	return (0);
}

/*
**see which way is the optimal way to rotate and then do so until it's at the top
*/

int	ft_calc_rr_dir(t_cont *cont, int pos)
{
	int	i;

	i = 0;
	while (cont->a->stack[i] != pos)
		i++;
	if ((cont->a->top - 1) - i < i)
	{
		while (cont->a->stack[cont->a->top - 1] != pos)
			ft_ra(cont);
	}
	else
	{
		while (cont->a->stack[cont->a->top - 1] != pos)
			ft_rra(cont);
	}
	return (0);
}

/*
** saves position of the first time you rotate
*/

int	ft_save_plus_rotate(t_cont *cont, int *pos)
{
	if (*pos == -1)
		*pos = cont->a->stack[cont->a->top - 1];
	ft_ra(cont);
	return (0);
}
