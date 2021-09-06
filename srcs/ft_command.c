/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 04:33:52 by romain            #+#    #+#             */
/*   Updated: 2021/09/06 22:20:54 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**possibly make functions for printing output or make it part of algo
*/

int	ft_swap(t_stack *stck)
{
	int	i;
	int	hold;

	i = stck->top;
	hold = stck->stack[i - 1];
	stck->stack[i - 1] = stck->stack[i - 2];
	stck->stack[i - 2] = hold;
	return (0);
}

/*
**top goes to the bottom of the stack
*/

int	ft_rotate(t_stack *stck)
{
	int	hold;
	int	i;

	i = stck->top - 1;
	hold = stck->stack[i];
	while (i > 0)
	{
		stck->stack[i] = stck->stack[i - 1];
		i--;
	}
	stck->stack[0] = hold;
	return (0);
}

int	ft_rrotate(t_stack *stck)
{
	int	hold;
	int	i;

	i = 0;
	hold = stck->stack[i];
	while (i < stck->top - 1)//double check that this works
	{
		stck->stack[i] = stck->stack[i + 1];
		i++;
	}
	stck->stack[i] = hold;
	return (0);
}

int	ft_push(t_stack *from, t_stack *to)
{
	to->stack[to->top] = from->stack[from->top - 1];
	to->top++;
	from->top--;
	return (0);
}

int	ft_pb(t_cont *cont)
{
	ft_push(cont->A, cont->B);
	printf("pb\n");
	return (0);
}
