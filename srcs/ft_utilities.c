/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:50:32 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/09 15:14:02 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_biggest(t_stack *stack)
{
	int i;
	int biggest;
	int position;

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