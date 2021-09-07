/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:12:31 by romain            #+#    #+#             */
/*   Updated: 2021/09/07 13:01:09 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_sa(t_cont *cont)
{
	ft_swap(cont->A);
	printf("sa\n");
	return (0);
}

int	ft_sb(t_cont *cont)
{
	ft_swap(cont->B);
	printf("sb\n");
	return (0);
}

int	ft_ss(t_cont *cont)
{
	ft_swap(cont->A);
	ft_swap(cont->B);
	printf("ss");
	return (0);
}

int	ft_ra(t_cont *cont)
{
	ft_rotate(cont->A);
	printf("ra\n");
	return (0);
}

int	ft_rb(t_cont *cont)
{
	ft_rotate(cont->B);
	printf("rb\n");
	return (0);
}
