/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:20:48 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/06 17:13:30 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//3, 5, 100, 500
int	ft_three_size(t_cont *cont)
{
	int i;

	i = 0;
	if (cont->A->stack[0] > cont->A->stack[1] && cont->A->stack[0] > \
	cont->A->stack[2])
	{
		ft_rra(cont);
		if (cont->A->stack[0] > cont->A->stack[1])
			ft_sa(cont);
	}
}