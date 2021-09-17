/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:12:31 by romain            #+#    #+#             */
/*   Updated: 2021/09/17 16:31:43 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_sa(t_cont *cont)
{
	ft_swap(cont->a);
	printf("sa\n");
	return (0);
}

int	ft_sb(t_cont *cont)
{
	ft_swap(cont->b);
	printf("sb\n");
	return (0);
}

int	ft_ss(t_cont *cont)
{
	ft_swap(cont->a);
	ft_swap(cont->b);
	printf("ss\n");
	return (0);
}

int	ft_ra(t_cont *cont)
{
	ft_rotate(cont->a);
	printf("ra\n");
	return (0);
}

int	ft_rb(t_cont *cont)
{
	ft_rotate(cont->b);
	printf("rb\n");
	return (0);
}
