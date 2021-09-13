/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_command2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:51:19 by romain            #+#    #+#             */
/*   Updated: 2021/09/13 23:28:46 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_rr(t_cont *cont)
{
	ft_rotate(cont->a);
	ft_rotate(cont->b);
	printf("rr\n");
	return (0);
}

int	ft_rra(t_cont *cont)
{
	ft_rrotate(cont->a);
	printf("rra\n");
	return (0);
}

int	ft_rrb(t_cont *cont)
{
	ft_rrotate(cont->b);
	printf("rrb\n");
	return (0);
}

int	ft_rrr(t_cont *cont)
{
	ft_rrotate(cont->a);
	ft_rrotate(cont->b);
	printf("rrr\n");
	return (0);
}

int	ft_pa(t_cont *cont)
{
	if (ft_push(cont->b, cont->a) == 0)
		printf("pa\n");
	else
		printf("ERROR: Pushed A with an empty stack\n");
	return (0);
}
