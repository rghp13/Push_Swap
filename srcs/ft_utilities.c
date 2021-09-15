/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:50:32 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/14 18:26:21 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_biggest(t_stack *stack)
{
	int	i;
	int	biggest;
	int	position;

	i = 0;
	position = 0;
	biggest = 0x80000000;
	while (i < stack->top)
	{
		if (biggest < stack->stack[i])
		{
			biggest = stack->stack[i];
			position = i;
		}
		i++;
	}
	return (position);
}

int	ft_sep_parse(t_cont *cont, char **separated)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	ft_sep_check_forbidden(cont, separated);
	while (i < cont->stack_max)
	{
		cont->a->stack[k] = ft_atoi(separated[i]);
		i++;
		cont->a->top = ++k;
	}
	ft_check_duplicate(cont);
	return (0);
}

int	ft_set_duplicate(int *duplicate, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		duplicate[i] = -1;
		i++;
	}
	return (0);
}

int	ft_find_missing(int *duplicate, int max)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	while (i < max)
	{
		if (duplicate[i] == -1)
		{
			if (ret == -1)
				ret = i;
			else
			{
				printf("ERROR: More than 1 missing number ft_make_relative");
				return (-1);
			}
		}
		i++;
	}
	return (ret);
}

int	ft_array_swap(t_stack *a, int *duplicate)
{
	free(a->stack);
	a->stack = duplicate;
	return (0);
}

int	ft_check_sorted(t_cont *cont)//if sorted return 0, if not return 1
{
	int	i;

	i = 0;
	while (i < cont->a->top - 1)
	{
		if (cont->a->stack[i] > cont->a->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}
