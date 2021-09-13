/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:20:48 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/13 23:31:18 by romain           ###   ########.fr       */
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
	if (cont->stack[max] < cont->stack[max - 1] && cont->stack[max] < \
	cont->stack[max - 2])
	{
		ft_ra(container);
		if (cont->stack[max] < cont->stack[max - 1])
			ft_sa(container);
	}
	else if (cont->stack[max - 1] < cont->stack[max] && cont->stack[max - 1] < \
	cont->stack[max - 2])
	{
		ft_rra(container);
		if (cont->stack[max] < cont->stack[max - 1])
			ft_sa(container);
	}
	else if (cont->stack[max - 2] < cont->stack[max] && cont->stack[max - 2] < \
	cont->stack[max - 1])
	{
		if (cont->stack[max] < cont->stack[max - 1])
			ft_sa(container);
	}
	return (0);
}

int	ft_push_three(t_cont *cont)
{
	int	push;

	while (cont->a->top > 3)
	{
		push = ft_find_biggest(cont->a);
		while (push < cont->a->top - 1)
		{
			if (push == cont->a->top - 2)
				ft_sa(cont);
			else if (push == 0 || push == 1)
				ft_rra(cont);
			else
				ft_ra(cont);
			push = ft_find_biggest(cont->a);
		}
		ft_pb(cont);
	}
	return (0);
}

int	ft_five_size(t_cont *cont)
{
	int	max;
	int	*stack;

	max = cont->stack_max;
	stack = cont->a->stack;
	ft_push_three(cont);
	ft_three_size(cont->a, cont);
	while (cont->b->top > 0)
		ft_pa(cont);
	return (0);
}
