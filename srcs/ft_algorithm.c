/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:20:48 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/07 14:44:35 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**Making assumption that there are only 3 items, I might need to make a version
**that doesn't assume that we want stack A and that there are only 3 items
** in said stack
*/

int	ft_three_size(t_stack *cont, t_cont *container)
{
	int max;

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
	else
		printf("Error, three size func failed all 3 conditions\n");
	return (0);
}
