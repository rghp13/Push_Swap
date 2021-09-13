/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:50:32 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/13 23:27:50 by romain           ###   ########.fr       */
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
