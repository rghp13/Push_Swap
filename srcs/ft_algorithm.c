/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:20:48 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/15 17:43:51 by romain           ###   ########.fr       */
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

int	ft_one_hun_size(t_cont *cont)
{
	unsigned int	mask;
	int				i;

	mask = 1;
	i = 0;
	while()//make external loop think about how to stop loop when there are no more relevant bits at the position
	while (cont->a->top > 0 && ft_check_bit(cont->a, mask))
	{
		if (cont->a->stack[cont->a->top - 1] & mask)
			ft_pb(cont);
		else
			ft_ra(cont);
		i++;
	}
}

/*
**possible bug, what if there's a bit where every entry has a 1 at that spot?
*/

int	ft_check_bit(t_stack *a, unsigned int mask)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->stack[i] & mask)
			return (1);
		i++;
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
