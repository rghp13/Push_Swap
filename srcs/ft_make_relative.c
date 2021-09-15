/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_relative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:38:48 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/14 18:25:03 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**Goal is to first make a duplicate stack.
**find the position of the smallest number and on the duplicate stack in the
**same position give it a value of 0 increasing by 1 for every further iteration
**so a 20 num stack has a set of 0-19 where every number stands for it's
**relative value compared to others.
** doing so will remove all negative numbers allowing me to use radix sort
*/

int	ft_find_smallest(t_stack *a, int max)
{
	int	sval;
	int	spos;
	int	i;

	i = 0;
	spos = -1;
	sval = 0x7fffffff;
	while (i < max)
	{
		if (sval > a->stack[i])
		{
			sval = a->stack[i];
			spos = i;
		}
		i++;
	}
	if (sval != 0x7fffffff)
		a->stack[spos] = 0x7fffffff;
	return (spos);
}

int	ft_make_relative(t_stack *a, int max)
{
	int	*duplicate;
	int	i;
	int	k;

	k = 0;
	duplicate = malloc(sizeof(int) * max);
	if (duplicate == NULL)
		return (-1);
	ft_set_duplicate(duplicate, max);
	while (k < max)
	{
		i = ft_find_smallest(a, max);
		if (i == -1)
		{
			i = ft_find_missing(duplicate, max);
			if (i == -1)
			{
				free(duplicate);
				return (-1);
			}
		}
		duplicate[i] = k++;
	}
	ft_array_swap(a, duplicate);
	return (0);
}
