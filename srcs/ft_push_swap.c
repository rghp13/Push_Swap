/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:49:46 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/21 13:06:55 by rponsonn         ###   ########.fr       */
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
	container->a = NULL;
	container->b = NULL;
	container->a = malloc(sizeof(t_stack));
	container->b = malloc(sizeof(t_stack));
	if (container->a == NULL || container->b == NULL)
		ft_free_exit(container);//leak for not including separated
	container->a->stack = NULL;
	container->b->stack = NULL;
	container->separated = separated;
	return (container);
}

int	ft_init_values(int argc, t_cont *cont)
{
	cont->stack_max = argc - 1;
	cont->a->stack = malloc(sizeof(int) * (cont->stack_max));
	cont->b->stack = malloc(sizeof(int) * (cont->stack_max));
	if (cont->a->stack == NULL || cont->b->stack == NULL)
		ft_free_exit(cont);
	cont->a->top = 0;
	cont->b->top = 0;
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
	if (ft_check_sorted(cont) == 0)
		return (0);
	if (cont->stack_max == 3)
		ft_three_size(cont->a, cont);
	else if (cont->stack_max <= 5)
		ft_five_size(cont);
	else if (cont->stack_max <= 500)
		ft_one_hun_size(cont);
/*	else
		ft_five_hun_size(cont);*/
//	if (ft_check_sorted(cont) == 1)
//		printf("Failed to sort properly\n");
	return (0);
}

int	ft_pushswap(int argc, char **argv)
{
	t_cont	*cont;
	char	**separated_input;
	int		i;

	i = 0;
	cont = NULL;
	separated_input = NULL;
	if (argc <= 1)
		ft_exit();
	else if (argc == 2)//put this in a function to save lines
	{
		separated_input = ft_split(argv[1], ' ');//forgot to test for null
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
//	for ( int y = 0; y < cont->a->top; y++)
//		printf("P %d, V %d\n", y, cont->a->stack[y]);
	if (ft_make_relative(cont->a, cont->stack_max) == -1)
		ft_free_exit(cont);

	ft_pick_sort(cont);
//	for (int x = 0; x < cont->a->top; x++)
//		printf("Value %d at position %d\n", cont->a->stack[x], x);
	ft_free(cont);
	return (0);
}
