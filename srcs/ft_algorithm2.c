/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:12:15 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/24 00:58:37 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**all 1 or all 0 check
**you don't want to push b if every number is a 0
*/

int	ft_check_zero_bit(t_stack *a, unsigned int mask)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->stack[i] & mask)
			i++;
		else
			break ;
	}
	if (i == a->top)
		return (1);
	i = 0;
	while (i < a->top)
	{
		if ((a->stack[i] & mask) == 0)
			i++;
		else
			break ;
	}
	if (i == a->top)
		return (1);
	return (0);
}

/*
**Check for any 0
*/

int	ft_check_bit(t_stack *a, unsigned int mask)
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
	ft_push_three(cont);
	ft_three_size(cont->a, cont);
	while (cont->b->top > 0)
		ft_pa(cont);
	return (0);
}
