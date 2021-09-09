/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_command2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:51:19 by romain            #+#    #+#             */
/*   Updated: 2021/09/09 15:36:02 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_rr(t_cont *cont)
{
	ft_rotate(cont->A);
	ft_rotate(cont->B);
	printf("rr\n");
	return (0);
}

int	ft_rra(t_cont *cont)
{
	ft_rrotate(cont->A);
	printf("rra\n");
	return (0);
}

int	ft_rrb(t_cont *cont)
{
	ft_rrotate(cont->B);
	printf("rrb\n");
	return (0);
}

int	ft_rrr(t_cont *cont)
{
	ft_rrotate(cont->A);
	ft_rrotate(cont->B);
	printf("rrr\n");
	return (0);
}

int	ft_pa(t_cont *cont)
{
	if (ft_push(cont->B, cont->A) == 0)
		printf("pa\n");
	else
		printf("ERROR: Pushed A with an empty stack\n");
	return (0);
}
