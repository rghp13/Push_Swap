/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:49:46 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/13 16:55:01 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**Rework parse to deal with 1 "2 3 4" 5 you can't rely on argc
**
**URGENT
**the first number in the stack is supposed to be the oldest.start from
**position max - 1 and not from 0
** end result should look like 0, 1, 2, 3
*/

t_cont	*ft_init_cont(char **separated)
{
	t_cont	*container;

	container = NULL;
	container = malloc(sizeof(t_cont));
	if (container == NULL)
		ft_exit();
	container->A = NULL;
	container->B = NULL;
	container->A = malloc(sizeof(t_stack));
	container->B = malloc(sizeof(t_stack));
	if (container->A == NULL || container->B == NULL)
		ft_free_exit(container);
	container->A->stack = NULL;
	container->B->stack = NULL;
	container->separated = separated;
	return (container);
}

int	ft_init_values(int argc, t_cont *cont)
{
	cont->stack_max = argc - 1;
	cont->A->stack = malloc(sizeof(int) * (cont->stack_max));
	cont->B->stack = malloc(sizeof(int) * (cont->stack_max));
	if (cont->A->stack == NULL || cont->B->stack == NULL)
		ft_free_exit(cont);
	cont->A->top = 0;
	cont->B->top = 0;
	return (0);
}

t_cont	*ft_init(int argc, char **separated)
{
	t_cont	*container;

	container = ft_init_cont(separated);
	ft_init_values(argc, container);
	return (container);
}

int	ft_pick_sort(t_cont *cont)
{
	if (cont->stack_max == 3)
		ft_three_size(cont->A, cont);
	else if (cont->stack_max <= 5)
		ft_five_size(cont);
/*	else if (cont->stack_max < 100)
		ft_one_hun_size(cont);
	else
		ft_five_hun_size(cont);*/
	return (0);
}

int	ft_pushswap(int argc, char **argv)
{
	t_cont	*cont;
	char	**separated_input;
	int		i;

	i = 0;
	separated_input = NULL;
	if (argc <= 1)
		ft_exit();
	else if (argc == 2)
	{
		separated_input = ft_split(argv[1], ' ');
		while (separated_input[i])
			i++;
		cont = ft_init(i + 1, separated_input);
		ft_sep_parse(cont, separated_input);
	}
	else
	{
		cont = ft_init(argc, separated_input);
		ft_parse(cont, argv);
	}
	ft_pick_sort(cont);
	ft_free(cont);
	return (0);
}