/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:49:46 by romain            #+#    #+#             */
/*   Updated: 2021/05/28 00:57:28 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**Potentially look into moving all the code from main to this function
**and move the init function into the parser
*/

t_cont	*ft_init_cont(void)
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
	return (container);
}

int		ft_init_values(int argc, t_cont *cont)
{
	cont->stack_max = argc - 1;
	cont->A->stack = malloc(sizeof(int)*(cont->stack_max));
	cont->B->stack = malloc(sizeof(int)*(cont->stack_max));
	if (cont->A->stack == NULL || cont->B->stack == NULL)
		ft_free_exit(cont);
	cont->A->top = 0;
	cont->B->top = 0;
	return (0);
}

t_cont	*ft_init(int argc)
{
	t_cont	*container;

	container = ft_init_cont();
	ft_init_values(argc, container);
	return (container);
}

int		ft_pushswap(int argc, char **argv)
{
	t_cont	*cont;
	int i;

	i = 0;
	if (argc <= 1)
		ft_exit();
	else if (argc == 2)
		return (0);
	cont = ft_init(argc);
	ft_parse(cont, argv);
	while (i < cont->A->top)
	{
		printf("Position = %d Value = %d\n", i, cont->A->stack[i]);
		i++;
	}
	ft_free(cont);
	return (0);
}