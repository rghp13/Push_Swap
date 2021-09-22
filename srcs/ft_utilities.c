/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:50:32 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/22 17:00:49 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_small(t_stack *stack)
{
	int	i;
	int	smallest;
	int	position;

	i = 0;
	position = 0;
	smallest = 0x7fffffff;
	while (i < stack->top)
	{
		if (smallest > stack->stack[i])
		{
			smallest = stack->stack[i];
			position = i;
		}
		i++;
	}
	return (position);
}

int	ft_sep_parse(t_cont *cont, char **separated)
{
	int		i;
	int		k;
	long	hold;

	i = 0;
	k = cont->stack_max - 1;
	ft_sep_check_forbidden(cont, separated);
	while (i < cont->stack_max)
	{
		hold = ft_atol(separated[i]);
		if (hold > 0x7fffffff || hold < -2147483648)
			ft_free_exit(cont);
		cont->a->stack[k] = (int)hold;
		i++;
		cont->a->top += 1;
		--k;
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
