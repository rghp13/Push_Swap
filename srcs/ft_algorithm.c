/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:20:48 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/21 12:44:35 by rponsonn         ###   ########.fr       */
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
	int				pos;

	mask = 1;
	while(mask)
	{
		if (ft_check_zero_bit(cont->a, mask))//all 1 or all 0
		{
			mask = mask << 1;
			continue;
		}
		pos = -1;
		while (cont->a->top > 0 && ft_check_bit(cont->a, mask))//is there a 0?
		{
			if ((cont->a->stack[cont->a->top - 1] & mask) == 0)
				ft_pb(cont);
			else
				ft_save_plus_rotate(cont, &pos);
		}
		ft_calc_rr_dir(cont, pos);
		while (cont->b->top > 0)//now push it all back
			ft_pa(cont);
		mask = mask << 1;
	}
	return (0);
}

int	ft_calc_rr_dir(t_cont *cont, int pos)//see which way is the optimal way to rotate and then do so until it's at the top
{
	int i;

	i = 0;
	while (cont->a->stack[i] != pos)
		i++;
	if ((cont->a->top - 1) - i < i)//if it's closer to the top of the stack
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


int	ft_save_plus_rotate(t_cont *cont, int *pos)//save pos of first 1
{
	if (*pos == -1)
		*pos = cont->a->stack[cont->a->top - 1];
	ft_ra(cont);
	return (0);
}

/*
**possible bug, what if there's a bit where every entry has a 1 at that spot?
*/

int	ft_check_zero_bit(t_stack *a, unsigned int mask)//check for all 0 or 1
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->stack[i] & mask) //check for all 1
			i++;
		else
			break;
	}
	if (i == a->top)
		return (1);
	i = 0;
	while (i < a->top)
	{
		if ((a->stack[i] & mask) == 0)
			i++;
		else
			break;
	}
	if (i == a->top)
		return (1);
	return (0);
}

int	ft_check_bit(t_stack *a, unsigned int mask)//check for any 0
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if ((a->stack[i] & mask) == 0)
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
