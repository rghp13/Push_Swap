/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:49:46 by romain            #+#    #+#             */
/*   Updated: 2021/05/24 18:57:49 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_cont	*ft_init(int argc, char **argv)
{
	t_cont	*container;

	if (!(container = malloc(sizeof(t_cont))))
		return (NULL);
	container->A = malloc(sizeof(t_stack));
	container->B = malloc(sizeof(t_stack));
	if (container->A == NULL || container->B == NULL)
		ft_free_exit(container);
	if (!(container->A->stack = malloc(sizeof(int)*(argc))))
		ft_free_exit(container);
	if (!(container->B->stack = malloc(sizeof(int)*(argc))))
		ft_free_exit(container);
	container->stack_max = argc;
}

int		ft_pushswap(int argc, char **argv)
{
	t_cont	*cont;

	cont = ft_init(cont, argc);
	if (cont == NULL)
		return (1);
	if (ft_parse(cont))
		return (-1);
	
}